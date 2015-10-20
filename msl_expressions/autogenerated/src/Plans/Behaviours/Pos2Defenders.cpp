using namespace std;
#include "Plans/Behaviours/Pos2Defenders.h"

/*PROTECTED REGION ID(inccpp1444834678756) ENABLED START*/ //Add additional includes here
#include <limits>
#include <engine/RunningPlan.h>
#include <robotmovement/RobotMovement.h>
using namespace std;

/*PROTECTED REGION END*/
namespace alica
{
	/*PROTECTED REGION ID(staticVars1444834678756) ENABLED START*/ //initialise static variables here
	/*PROTECTED REGION END*/
	Pos2Defenders::Pos2Defenders() :
			DomainBehaviour("Pos2Defenders")
	{
		/*PROTECTED REGION ID(con1444834678756) ENABLED START*/ //Add additional options here
		/*PROTECTED REGION END*/
	}
	Pos2Defenders::~Pos2Defenders()
	{
		/*PROTECTED REGION ID(dcon1444834678756) ENABLED START*/ //Add additional options here
		/*PROTECTED REGION END*/
	}
	void Pos2Defenders::run(void* msg)
	{
		/*PROTECTED REGION ID(run1444834678756) ENABLED START*/ //Add additional options here
		shared_ptr<geometry::CNPoint2D> alloBallPos = nullptr;
		alloBallPos = wm->ball.getAlloBallPosition();

		if (alloBallPos == nullptr)
		{

			alloBallPos = make_shared<geometry::CNPoint2D>(0, 0);
		}

		this->keeperPos = wm->robots.getTeamMatePosition(keeperId);
		int ownId = this->wm->getOwnId();
		auto ownEp = this->getRunningPlan()->getParent().lock()->getAssignment()->getEntryPointOfRobot(ownId);
		auto robotsInOwnEp = this->getRunningPlan()->getParent().lock()->getAssignment()->getRobotsWorking(ownEp);
		auto firstDefPos = alloBallPos + make_shared<geometry::CNPoint2D>(-2500, -600);
		auto secondDefPos = alloBallPos + make_shared<geometry::CNPoint2D>(-4000, 2300);
		auto firstDef = wm->robots.getTeamMatePosition((*robotsInOwnEp)[0]);
		msl_actuator_msgs::MotionControl mc;

		if (robotsInOwnEp->size() == 2)
		{

			auto secondDef = wm->robots.getTeamMatePosition((*robotsInOwnEp)[1]);
			//first Defender is closer to first position
			if (firstDef->distanceTo(firstDefPos) < secondDef->distanceTo(firstDefPos))
			{
				//i am first Defender
				if (ownId == (*robotsInOwnEp)[0])
				{

					mc = msl::RobotMovement::moveToPointCarefully(firstDefPos->alloToEgo(*firstDef),
																	alloBallPos->alloToEgo(*firstDef), 0);

				}
				else
				{
					mc = msl::RobotMovement::moveToPointCarefully(secondDefPos->alloToEgo(*secondDef),
																	alloBallPos->alloToEgo(*secondDef), 0);
				}

			}
			//second Defender is closer to first position
			else
			{
				//i am second Defender
				if (ownId == (*robotsInOwnEp)[0])
				{

					mc = msl::RobotMovement::moveToPointCarefully(secondDefPos->alloToEgo(*firstDef),
																	alloBallPos->alloToEgo(*firstDef), 0);

				}
				else
				{
					mc = msl::RobotMovement::moveToPointCarefully(firstDefPos->alloToEgo(*secondDef),
																	alloBallPos->alloToEgo(*secondDef), 0);
				}

			}

		}
		else
		{
			mc = msl::RobotMovement::moveToPointCarefully(firstDefPos->alloToEgo(*firstDef),
															alloBallPos->alloToEgo(*firstDef), 0);
		}

		send(mc);
		/*PROTECTED REGION END*/
	}
	void Pos2Defenders::initialiseParameters()
	{
		/*PROTECTED REGION ID(initialiseParameters1444834678756) ENABLED START*/ //Add additional options here
		// get the teammate which is the closest to the own goal mid (hopefully it is the keeper)
		auto positions = this->wm->robots.getPositionsOfTeamMates();
		auto ownGoalMid = msl::MSLFootballField::getInstance()->posOwnGoalMid();
		double smallestDist = std::numeric_limits<double>::max();
		for (auto pos : *positions)
		{
			if (pos->second != nullptr)
			{
				double tmpDist = pos->second->distanceTo(ownGoalMid);
				if (tmpDist < smallestDist)
				{
					smallestDist = tmpDist;
					this->keeperId = pos->first;
					this->keeperPos = pos->second;
				}
			}
		}

		/*PROTECTED REGION END*/
	}
/*PROTECTED REGION ID(methods1444834678756) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
