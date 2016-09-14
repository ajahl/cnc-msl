using namespace std;
#include "Plans/TestPlans/TestKick/TestDriveTo.h"

/*PROTECTED REGION ID(inccpp1472648297552) ENABLED START*/ //Add additional includes here
#include <Game.h>
#include "msl_robot/robotmovement/RobotMovement.h"
#include <RawSensorData.h>
#include <pathplanner/PathPlanner.h>
#include <MSLWorldModel.h>
#include <container/CNPoint2D.h>
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1472648297552) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    TestDriveTo::TestDriveTo() :
            DomainBehaviour("TestDriveTo")
    {
        /*PROTECTED REGION ID(con1472648297552) ENABLED START*/ //Add additional options here
        toX = 0;
        toY = 0;
        query = make_shared<msl::MovementQuery>();
        /*PROTECTED REGION END*/
    }
    TestDriveTo::~TestDriveTo()
    {
        /*PROTECTED REGION ID(dcon1472648297552) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void TestDriveTo::run(void* msg)
    {
        /*PROTECTED REGION ID(run1472648297552) ENABLED START*/ //Add additional options here
        auto ownPos = wm->rawSensorData->getOwnPositionVision();
        if (ownPos == nullptr)
            return;

        auto alloGoal = make_shared < geometry::CNPoint2D > (toX, toY);
        auto egoGoal = alloGoal->alloToEgo(*ownPos);

        query->dribble = true;
        query->egoDestinationPoint = egoGoal;
        query->egoAlignPoint = egoGoal;

        msl::RobotMovement rm;
        auto motionCommand = rm.moveToPoint(query);
        this->send(motionCommand);

        if (egoGoal->length() < 300)
        {
            this->setSuccess(true);
        }

        /*PROTECTED REGION END*/
    }
    void TestDriveTo::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1472648297552) ENABLED START*/ //Add additional options here
        sc = supplementary::SystemConfig::getInstance();

        string tmp;
        bool success = true;
        try
        {
            success &= getParameter("X", tmp);
            if (success)
            {
                this->toX = stod(tmp);
            }

            success &= getParameter("Y", tmp);
            if (success)
            {
                this->toY = stod(tmp);
            }
        }
        catch (exception& e)
        {
            throw e;
        }

        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1472648297552) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
