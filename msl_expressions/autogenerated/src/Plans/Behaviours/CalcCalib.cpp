using namespace std;
#include "Plans/Behaviours/CalcCalib.h"

/*PROTECTED REGION ID(inccpp1446033324019) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1446033324019) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    CalcCalib::CalcCalib() :
            DomainBehaviour("CalcCalib")
    {
        /*PROTECTED REGION ID(con1446033324019) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    CalcCalib::~CalcCalib()
    {
        /*PROTECTED REGION ID(dcon1446033324019) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void CalcCalib::run(void* msg)
    {
        /*PROTECTED REGION ID(run1446033324019) ENABLED START*/ //Add additional options here
        if (this->wm->rawSensorData.getOwnPositionVision(0) != NULL)
        {
            calibPosVision = this->wm->rawSensorData.getOwnPositionVision(0);
        }

        //calibPosMotion = this->wm->rawSensorData.getOwnPositionMotion(0);
        calibPosMotionX = this->wm->rawSensorData.getOwnPositionMotion(0)->x;

        calibPosMotionY = this->wm->rawSensorData.getOwnPositionMotion(0)->y;

        //std::cout << "posMotionX: " << calibPosMotionX << std::endl;
        //std::cout << "posMotionY: " << calibPosMotionY << std::endl;
        //std::cout<< "oldPositionX: "<< calibOldPosMotionX<<std::endl;
        //std::cout << "calibPosVisionX: "<< calibPosVision->x - calibOldPosVision->x<<endl;
        //std::cout << "calibPosVisionY: "<< calibPosVision->y - calibOldPosVision->y<<endl;
        //std::cout << "Theta: "<< this->wm->rawSensorData.getOwnPositionMotion(0)->theta<<endl;
        //std::cout << "" << endl;
        //std::cout << "correctedWayX : " << correctedWayX << std::endl;
        //std::cout << "correctedWayY : " << correctedWayY << std::endl;
        //std::cout << "theta : " << this->wm->rawSensorData.getOwnPositionVision(0)->theta - this->wm->rawSensorData.getOwnPositionMotion(0)->theta << std::endl;

        correctedWayX = (calibPosMotionX - calibOldPosMotionX)
                / cos(this->wm->rawSensorData.getOwnPositionVision(0)->theta
                        - this->wm->rawSensorData.getOwnPositionMotion(0)->theta);
        correctedWayY = (calibPosMotionY - calibOldPosMotionY)
                * tan(this->wm->rawSensorData.getOwnPositionVision(0)->theta
                        - this->wm->rawSensorData.getOwnPositionMotion(0)->theta);

        correctedPosX = correctedPosX + correctedWayX;
        correctedPosY = correctedPosY + correctedWayY;

        this->wm->calibData.length = this->wm->calibData.length
                + sqrt((correctedWayX) * (correctedWayX) + (correctedWayY) * (correctedWayY));

        calibOldPosMotionX = calibPosMotionX;
        calibOldPosMotionY = calibPosMotionY;

        //}
        /*PROTECTED REGION END*/
    }
    void CalcCalib::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1446033324019) ENABLED START*/ //Add additional options here
        diffX = correctedPosX - this->wm->rawSensorData.getOwnPositionVision(0)->x;
        diffY = correctedPosY - this->wm->rawSensorData.getOwnPositionVision(0)->y;

        if (this->wm->rawSensorData.getOwnPositionVision(0) != NULL)
        {
            auto deltax = this->wm->rawSensorData.getOwnPositionMotion(0)->x
                    - this->wm->rawSensorData.getOwnPositionVision(0)->x;
            auto deltay = this->wm->rawSensorData.getOwnPositionMotion(0)->y
                    - this->wm->rawSensorData.getOwnPositionVision(0)->y;

            string value;
            string filename = string(sc->getConfigPath()) + string(sc->getHostname()) + string("/CalibData.txt");
            ifstream calibData(filename);
            if (calibData.is_open())
            {
                while (getline(calibData, value))
                {
                    this->wm->calibData.calibCoefficient = std::stod(value);
                }
                calibData.close();
            }

            if (this->wm->calibData.calibCoefficient == 0)
            {
                this->wm->calibData.calibCoefficient = 0.85;
            }
            if (this->wm->calibData.length > 12000)
            {
                if (this->wm->calibData.length != 0)
                {
                    if (this->wm->calibData.length < 13200)
                    {
                        this->wm->calibData.calibCoefficient *= (sqrt(deltax * deltax + deltay * deltay)
                                / this->wm->calibData.length) + 1;
                    }
                    else
                    {
                        this->wm->calibData.calibCoefficient *= -(sqrt(deltax * deltax + deltay * deltay)
                                / this->wm->calibData.length) + 1;
                    }
                }

                string filename = string(sc->getConfigPath()) + string(sc->getHostname()) + string("/CalibData.txt");
                ofstream saveToCalibData;
                saveToCalibData.open(filename);
                saveToCalibData << this->wm->calibData.calibCoefficient;
                saveToCalibData.close();
            }
            std::cout << "Differenzen: " << std::endl;
            std::cout << "X: " << diffX << std::endl;
            std::cout << "Y: " << diffY << std::endl;
            std::cout << "Länge: " << this->wm->calibData.length << std::endl;
            std::cout << "Faktor: " << this->wm->calibData.calibCoefficient << std::endl;
            std::cout << "posMotionX: " << this->wm->rawSensorData.getOwnPositionMotion(0)->x << std::endl;
            std::cout << "posMotionY: " << this->wm->rawSensorData.getOwnPositionMotion(0)->y << std::endl;
            std::cout << "correctedWayX : " << correctedPosX << std::endl;
            std::cout << "correctedWayY : " << correctedPosY << std::endl;
            std::cout << "posVisionX: " << this->wm->rawSensorData.getOwnPositionVision(0)->x << std::endl;
            std::cout << "posVisionY: " << this->wm->rawSensorData.getOwnPositionVision(0)->y << std::endl;
            std::cout << "theta : "
                    << this->wm->rawSensorData.getOwnPositionVision(0)->theta
                            - this->wm->rawSensorData.getOwnPositionMotion(0)->theta << std::endl;

            std::cout << "" << std::endl;
        }

        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1446033324019) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
