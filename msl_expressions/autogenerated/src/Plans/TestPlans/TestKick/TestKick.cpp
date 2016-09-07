using namespace std;
#include "Plans/TestPlans/TestKick/TestKick.h"

/*PROTECTED REGION ID(inccpp1472648360493) ENABLED START*/ //Add additional includes here
#include <Game.h>
#include "msl_robot/robotmovement/RobotMovement.h"
#include "msl_actuator_msgs/KickControl.h"
#include <RawSensorData.h>
#include <pathplanner/PathPlanner.h>
#include <MSLWorldModel.h>
#include <container/CNPoint2D.h>

/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1472648360493) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    TestKick::TestKick() :
            DomainBehaviour("TestKick")
    {
        /*PROTECTED REGION ID(con1472648360493) ENABLED START*/ //Add additional options here
    	query = make_shared<msl::MovementQuery>();
        /*PROTECTED REGION END*/
    }
    TestKick::~TestKick()
    {
        /*PROTECTED REGION ID(dcon1472648360493) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void TestKick::run(void* msg)
    {
        /*PROTECTED REGION ID(run1472648360493) ENABLED START*/ //Add additional options here
    	auto ownPos = wm->rawSensorData->getOwnPositionVision();

		if (ownPos == nullptr)
			return;

		auto alloGoal = wm->field->posOppGoalMid();
		auto egoGoal = alloGoal->alloToEgo(*ownPos);

		query->egoAlignPoint = egoGoal;
		query->dribble = true;

		msl::RobotMovement rm;
		auto motionCommand = rm.moveToPoint(query);


		cout << "Angle to: " << egoGoal->angleTo() << endl;
		if (fabs(egoGoal->angleTo()) < 0.02)
		{
			msl_actuator_msgs::KickControl kickCmd;
			kickCmd.enabled = true;
			kickCmd.power = 2000;

			this->send(kickCmd);
			this->setSuccess(true);
		}
        /*PROTECTED REGION END*/
    }
    void TestKick::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1472648360493) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1472648360493) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
