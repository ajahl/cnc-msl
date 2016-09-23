/*
 * ballhandle.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: Lukas Will
 */

#include "BallHandle.h"

#include <BeaglePWM.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <SystemConfig.h>

#include "msl_actuator_msgs/BallHandleCmd.h"
#include "msl_actuator_msgs/BallHandleMode.h"

BallHandle::BallHandle() {
	const char *BH_right_pins[] = { "P8_9", "P8_10", "P8_16", "P8_18" };
	const char *BH_left_pins[] = { "P8_7", "P8_8", "P8_12", "P8_14" };

	rightMotor = new Motor(BeaglePWM::P8_19, BH_right_pins, maxSpeed);
	leftMotor = new Motor(BeaglePWM::P8_13, BH_left_pins, maxSpeed);
	
	readConfigParameters();

	killThread = false;
	notifyThread = false;
	bhThread = new std::thread(&BallHandle::controlBallHandle, this);
}

BallHandle::~BallHandle() {
	killThread = true;
	cv.notify_all();

	delete bhThread;
	delete rightMotor;
	delete leftMotor;
}

void BallHandle::readConfigParameters() {
	supplementary::SystemConfig* sys = supplementary::SystemConfig::getInstance();

	timeout = (*sys)["Actuation"]->get<double>("Actuation.PingInterval", NULL);
	handlerSpeedFactor = (*sys)["Actuation"]->get<double>("Dribble.SpeedFactor", NULL);
	speedNoBall = (*sys)["Actuation"]->get<double>("Dribble.SpeedNoBall", NULL);
	handlerSpeedSummand = (*sys)["Actuation"]->get<double>("Dribble.SpeedSummand", NULL);
	slowTranslation = (*sys)["Actuation"]->get<double>("Dribble.SlowTranslation", NULL);
	slowTranslationWheelSpeed = (*sys)["Actuation"]->get<double>("Dribble.SlowTranslationWheelSpeed", NULL);
	curveRotationFactor = (*sys)["Actuation"]->get<double>("Dribble.CurveRotationFactor", NULL);
	orthoDriveFactor = (*sys)["Actuation"]->get<double>("Dribble.OrthoDriveFactor", NULL);

	shared_ptr < vector<string> > speedsSections = (*sys)["Actuation"]->getSections("ForwardDribbleSpeeds", NULL);
	vector<double> robotSpeed(speedsSections->size());
	vector<double> actuatorSpeed(speedsSections->size());
	int i = 0;
	for (string subsection : *speedsSections)
	{
		robotSpeed[i] = (*sys)["Actuation"]->get<double>("ForwardDribbleSpeeds", subsection.c_str(), "robotSpeed", NULL);
		actuatorSpeed[i] = (*sys)["Actuation"]->get<double>("ForwardDribbleSpeeds", subsection.c_str(), "actuatorSpeed", NULL);
		cout << "RobotSpeed: " << robotSpeed[i] << "actuatorSpeed: " << actuatorSpeed[i] << endl;
		i++;
	}
	forwardSpeedSpline.set_points(robotSpeed, actuatorSpeed, false);
}

void BallHandle::setOdometryData(double newAngle, double newTranslation) {
//	unique_lock<mutex> dataMutex(mtxData);
	angle = newAngle;
	translation = newTranslation;

	calculatedIMUSpeedX = 0;
	calculatedIMUSpeedY = 0;
}

void BallHandle::setIMUData(geometry::CNPoint3D acceleration, geometry::CNPoint3D newRotation, uint64_t timeDifference_us) {
//	unique_lock<mutex> dataMutex(mtxData);
	calculatedIMUSpeedX += acceleration.x * ((double) timeDifference_us / 1000000);
	calculatedIMUSpeedY += acceleration.y * ((double) timeDifference_us / 1000000);
	rotation = newRotation.z;
}

void BallHandle::controlBallHandle() {
	msl_actuator_msgs::BallHandleMode msg;
	unique_lock<mutex> ballHandleMutex(mtx);
	while(!killThread) {
		cv.wait(ballHandleMutex, [&] { return killThread || notifyThread; }); // protection against spurious wake-ups
		if (killThread)
			break;

		try {
			switch (getMode())
			{
				case msg.AUTONOMOUS_CONTROL:
					dribbleControl();
					break;

				case msg.REMOTE_CONTROL:
					checkTimeout();
					break;

				default:
					checkTimeout();
					break;
			}
		} catch (exception &e) {
			cout << "BallHanlde: " << e.what() << endl;
		}

		notifyThread = false;
	}
}

void BallHandle::notify() {
	notifyThread = true;
	cv.notify_all();
}

void BallHandle::dribbleControl() {
//	unique_lock<mutex> dataMutex(mtxData);
	double l = 0;
	double r = 0;
	double orthoL = 0;
	double orthoR = 0;
	double speedDC = 0;
	double speedX = cos(angle) * translation + calculatedIMUSpeedX * 1000;
	double speedY = sin(angle) * translation + calculatedIMUSpeedY * 1000;
	int speedL = 0;
	int speedR = 0;

	if (rotation < 0)
	{
		l = 0;
		r = abs(rotation) / M_PI * curveRotationFactor;
	}
	else
	{
		r = 0;
		l = abs(rotation) / M_PI * curveRotationFactor;
	}

	//ignor rotation error
	if (fabs(rotation) < 0.04)
	{
		l = 0;
		r = 0;
	}

	//langsam vorwaerts
	if (speedX > -slowTranslation && speedX < 40)
	{
		speedDC = slowTranslationWheelSpeed;
	}
	//langsam rueckwaerts
	else if (speedX < slowTranslation && speedX >= 40)
	{
		speedDC = -slowTranslationWheelSpeed;
	}
	//schnell vor
	else if (speedX <= -slowTranslation)
	{
		//0.5 is for correct rounding
		speedDC = max(-10000, min(10000, (int) (forwardSpeedSpline(speedX) + 0.5)));
		if (rotation > -1.0 && rotation < 1.0 && speedX <= -800)
		{
			l = 0;
			r = 0;
		}
	}
	//schnell rueck
	else
	{
		speedDC = max(-10000, min(10000, (int) (3 * handlerSpeedFactor * speedX / 100.0)));
	}

	//geschwindigkeitsanteil fuer orthogonal zum ball
	if (speedY > 0)
	{
		//nach rechts fahren
		orthoR = speedY * orthoDriveFactor;
		orthoL = -speedY * orthoDriveFactor / 2.0;
	}
	else
	{
		//nach links fahren
		orthoR = speedY * orthoDriveFactor / 2.0;
		orthoL = -speedY * orthoDriveFactor;
	}

	speedL = speedDC + l + orthoL;
	speedR = speedDC + r + orthoR;

	//leftMotor->setSpeed(speedL);
	//rightMotor->setSpeed(speedR);

	printf("DribbleControl:  Left: %i  -  Right: %i\n", speedL, speedR);
}

void BallHandle::setBallHandling(int32_t speedL, int32_t speedR) {
	leftMotor->setSpeed(speedL);
	rightMotor->setSpeed(speedR);
	printf("REMOTE:  Left: %i  -  Right: %i\n", speedL, speedR);
}

void BallHandle::ping() {
//	unique_lock<mutex> pingMutex(mtxPing);
	gettimeofday(&last_ping, NULL);
}

void BallHandle::checkTimeout() {
	timeval	t;
	gettimeofday(&t, NULL);
//	unique_lock<mutex> pingMutex(mtxPing);
	if (TIMEDIFFMS(t, last_ping) > timeout) {
		this->setBallHandling(0, 0);
	}
}


uint8_t BallHandle::getMode() {
//	unique_lock<mutex> modeMutex(mtxMode);
	return mode;
}

void BallHandle::setMode(uint8_t newMode) {
//	unique_lock<mutex> modeMutex(mtxMode);
	mode = newMode;
}
