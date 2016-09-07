using namespace std;
#include "Plans/TestPlans/TestKick/TestGetBall.h"

/*PROTECTED REGION ID(inccpp1472647957600) ENABLED START*/ //Add additional includes here
#include <Game.h>
#include "msl_robot/robotmovement/RobotMovement.h"
#include <RawSensorData.h>
#include <Ball.h>
#include <obstaclehandler/Obstacles.h>
#include <pathplanner/PathPlanner.h>
#include <msl_actuator_msgs/BallHandleCmd.h>
#include <MSLWorldModel.h>
#include <container/CNPoint2D.h>
#include <container/CNPosition.h>
#include <container/CNVelocity2D.h>
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1472647957600) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    TestGetBall::TestGetBall() :
            DomainBehaviour("TestGetBall")
    {
        /*PROTECTED REGION ID(con1472647957600) ENABLED START*/ //Add additional options here
    	query = make_shared<msl::MovementQuery>();
        /*PROTECTED REGION END*/
    }
    TestGetBall::~TestGetBall()
    {
        /*PROTECTED REGION ID(dcon1472647957600) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void TestGetBall::run(void* msg)
    {
        /*PROTECTED REGION ID(run1472647957600) ENABLED START*/ //Add additional options here
        auto egoBallPos = wm->ball->getEgoBallPosition();
        if (egoBallPos == nullptr)
            return;

        query->egoDestinationPoint = egoBallPos;
        query->egoAlignPoint = egoBallPos;

        msl::RobotMovement rm;
        auto motionCommand = rm.moveToPoint(query);
        this->send(motionCommand);

        if (wm->ball->haveBall())
        {
            this->setSuccess(true);
        }
        /*PROTECTED REGION END*/
    }
    void TestGetBall::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1472647957600) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1472647957600) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
