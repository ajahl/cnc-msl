#include "Plans/GenericStandards/constraints/GenericExecute1431522123418Constraints.h"
using namespace std;
using namespace alica;
/*PROTECTED REGION ID(ch1431522123418) ENABLED START*/
#include <memory>
#include "AutoDiff.h"
#include "MSLConstraintBuilder.h"
#include "MSLFootballField.h"
#include "engine/constraintmodul/SolverTerm.h"
#include "engine/constraintmodul/ConstraintDescriptor.h"
#include "MSLWorldModel.h"
/*PROTECTED REGION END*/

namespace alicaAutogenerated
{
    //Plan:GenericExecute

    /*		
     * Tasks: 
     * - EP:1431522155980 : StandardExecuter (1238601692867)
     * - EP:1431522269326 : StandardReceiver (1238601842183)
     * - EP:1431523395534 : Blocker (1432209050494)
     * - EP:1431523422152 : Defend (1225115406909)
     *
     * States:
     * - GrabBall (1431522155979)
     * - Align (1431522297705)
     * - Pass (1431522763494)
     * - Receive (1431522912251)
     * - Success (1431522995646)
     * - Block (1431523482646)
     * - Defend (1431524014799)
     * - SpatialDefend (1431524769489)
     * - Align (1433949667740)
     *
     * Vars:
     */

    /*
     * RuntimeCondition - (Name): NewRuntimeCondition
     * (ConditionString): 
     * Static Variables: []
     * Domain Variables:

     * forall agents in Blocker let v = [x, y] 

     * forall agents in Defend let v = [x, y] 

     */
    void Constraint1457955744730::getConstraint(shared_ptr<ConstraintDescriptor> c, shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(cc1457955744730) ENABLED START*/
        msl::MSLWorldModel* wm = msl::MSLWorldModel::get();
        auto constraint = autodiff::LTConstraint::TRUE;
        auto util = autodiff::TermBuilder::constant(0);
        auto domainVariables = c->getDomainVars();

        vector < shared_ptr < TVec >> poses;

        vector < shared_ptr < TVec >> defender;
        vector < shared_ptr < TVec >> blocker;

        vector < shared_ptr < geometry::CNPosition >> robotPositions;

        for (int i = 0; i < domainVariables->at(0)->size(); i++)
        {
            c->getDomainRanges()->at(0).at(i).at(0).at(0) = -msl::MSLFootballField::FieldLength / 2;
            c->getDomainRanges()->at(0).at(i).at(0).at(1) = msl::MSLFootballField::FieldLength / 2;
            c->getDomainRanges()->at(0).at(i).at(1).at(0) = -msl::MSLFootballField::FieldWidth / 2;
            c->getDomainRanges()->at(0).at(i).at(1).at(1) = msl::MSLFootballField::FieldWidth / 2;
            robotPositions.push_back(wm->robots.teammates.getTeamMatePosition(c->getAgentsInScope()->at(0)->at(i)));
            auto vec = make_shared < TVec
                    > (initializer_list<shared_ptr<Term>> {dynamic_pointer_cast < autodiff::Variable
                                                                   > (domainVariables->at(0)->at(i)->at(0)),
                                                           dynamic_pointer_cast < autodiff::Variable
                                                                   > (domainVariables->at(0)->at(i)->at(1))});
            poses.push_back(vec);
            blocker.push_back(vec);
        }
        for (int i = 0; i < domainVariables->at(1)->size(); i++)
        {
            c->getDomainRanges()->at(1).at(i).at(0).at(0) = -msl::MSLFootballField::FieldLength / 2;
            c->getDomainRanges()->at(1).at(i).at(0).at(1) = msl::MSLFootballField::FieldLength / 2;
            c->getDomainRanges()->at(1).at(i).at(1).at(0) = -msl::MSLFootballField::FieldWidth / 2;
            c->getDomainRanges()->at(1).at(i).at(1).at(1) = msl::MSLFootballField::FieldWidth / 2;
            robotPositions.push_back(wm->robots.teammates.getTeamMatePosition(c->getAgentsInScope()->at(1)->at(i)));
            auto vec = make_shared < TVec
                    > (initializer_list<shared_ptr<Term>> {dynamic_pointer_cast < autodiff::Variable
                                                                   > (domainVariables->at(1)->at(i)->at(0)),
                                                           dynamic_pointer_cast < autodiff::Variable
                                                                   > (domainVariables->at(1)->at(i)->at(1))});
            poses.push_back(vec);
            defender.push_back(vec);
        }

        cout << "DefendPlay: poses, blocker, defender" << poses.size() << " " << blocker.size() << " "
                << defender.size() << endl;
        // END INITILIZE VARIABLE CONTAINER

        shared_ptr < geometry::CNPoint2D > ballPose = wm->ball.getAlloBallPosition();
        if (ballPose == nullptr)
        {
            ballPose = make_shared < geometry::CNPoint2D > (0, 0);
        }
        shared_ptr < TVec > tvecBallPose = make_shared < TVec > (initializer_list<double> {ballPose->x, ballPose->y});
        auto ownGoalPos = msl::MSLFootballField::posOwnGoalMid();
        shared_ptr < TVec > ownGoalVec = make_shared < TVec > (initializer_list<double> {ownGoalPos->x, ownGoalPos->y});
        constraint = constraint & msl::MSLConstraintBuilder::applyRules(-1, poses);

        cout << "1111" << endl;
        //Just for the case when we use this after "start" has been pressed
        if (wm->game.getSituation() == msl::Situation::Start)
        {
            constraint = constraint
                    & msl::MSLConstraintBuilder::ownPenaltyAreaDistanceExceptionRule(tvecBallPose, poses);
        }

        auto opps = wm->robots.opponents.getOpponentsAlloClustered();

        vector < shared_ptr < TVec >> blockPositions;
        vector < shared_ptr < TVec >> blockOpponents;
        shared_ptr < geometry::CNPoint2D > nearestOpp = nullptr;
        //default nearest opp

        if (ballPose != nullptr)
            nearestOpp = make_shared < geometry::CNPoint2D > (ballPose->x - 250, ballPose->y);
        double dist = 999999999;

        if (opps != nullptr)
        {
            for (auto opp : *opps)
            {

                cout << "" << opp->toString() << endl;

                //is nearest to the ball?
                if (ballPose != nullptr)
                {
                    msl::MSLFootballField::mapOutOfOwnPenalty(opp, ballPose - opp);
                    double oDist = opp->distanceTo(ballPose);
                    if (oDist < dist)
                    {
                        nearestOpp = opp;
                        oDist = dist;
                    }
                }
                else
                {
                    opp = msl::MSLFootballField::mapOutOfOwnPenalty(opp);
                }

                //add blocking position
                shared_ptr < geometry::CNPoint2D > blockingPos;
                if (ballPose != nullptr)
                {
                    blockingPos = opp + (ballPose - opp)->normalize() * 700;
                }
                else
                {
                    blockingPos = make_shared < geometry::CNPoint2D > (opp->x - 700, opp->y);
                }

                //only add if opp is not close to the ball
                if (ballPose->distanceTo(blockingPos) > 1800 && ballPose->distanceTo(blockingPos) < 4000)
                {
                    blockPositions.push_back(
                            make_shared < TVec > (initializer_list<double> {blockingPos->x, blockingPos->y}));
                    blockOpponents.push_back(make_shared < TVec > (initializer_list<double> {opp->x, opp->y}));
                }

            }
        }
        // Make a defenderwall between ball and goal, care other robots
        //TODO check Is this good close to the own goal???
        if (defender.size() > 0)
        {
            auto direction = (ballPose - ownGoalPos)->normalize();
            auto wallPoint = direction
                    * min(ownGoalPos->distanceTo(msl::MSLFootballField::posULOppPenaltyArea()),
                          ballPose->distanceTo(ownGoalPos) / 2);
            wallPoint = wallPoint + ownGoalPos;

            auto directionTVec = make_shared < TVec > (initializer_list<double> {direction->x, direction->y});
            auto wallPointTVec = make_shared < TVec > (initializer_list<double> {wallPoint->x, wallPoint->y});
            for (int j = 0; j < defender.size(); j++)
            {
                vector < shared_ptr < Term >> diffTerm;
                diffTerm.push_back(defender.at(j)->getX() - autodiff::TermBuilder::constant(wallPoint->x));
                diffTerm.push_back(defender.at(j)->getY() - autodiff::TermBuilder::constant(wallPoint->y));
                auto g2def = make_shared < TVec > (diffTerm);
                auto relPoint = ConstraintBuilder::inCoordsOf(g2def, directionTVec);
                constraint = constraint
                        & ((shared_ptr<autodiff::Term> )make_shared < autodiff::Abs > (relPoint->getX())
                                < autodiff::TermBuilder::constant(200));
                util = util
                        + 100
                                * (1
                                        - (ConstraintBuilder::distanceSqr(defender.at(j), wallPointTVec)
                                                / (msl::MSLFootballField::MaxDistanceSqr)));
            }
            //c.Constraint &= ConstraintBuilder.Distance(defender[0],new AD.TVec(wallPoint.X,wallPoint.Y)) < 100;
        }
        if (blocker.size() > 0)
        {
            int opponents2BlockCount = blockPositions.size();
        	cout << "33 " << blocker.size()<< " " << opponents2BlockCount << endl;
            //constraint = constraint & msl::MSLConstraintBuilder::see(tvecBallPose, true, 10000, blocker);
            for (int k = 0; k < blocker.size(); k++)
            {
                //close to block positions
                auto blockUtil = autodiff::TermBuilder::constant(0);
                //for (int j = 0; j < min(opponents2BlockCount, (int)blocker.size()); j++)
                for (int j = 0; j < opponents2BlockCount; j++)
                {
                    blockUtil = make_shared < autodiff::Max
                            > (blockUtil, 10
                                    * (1
                                            - ((ConstraintBuilder::distanceSqr(blocker.at(k), blockPositions.at(j)))
                                                    / (msl::MSLFootballField::MaxDistanceSqr * blocker.size()))));
                }
                util = util + blockUtil;
                //Do not block more than 4 m away from the ball
                /*constraint = constraint
                        & ConstraintBuilder::distanceSqr(blocker.at(k), tvecBallPose)
                                < autodiff::TermBuilder::constant(4000 * 4000);
				*/

                //avoid opponents!
                for (int j = 0; j < opponents2BlockCount; j++)
                {
                    auto dist2Opp = ConstraintBuilder::distanceSqr(blocker.at(k), blockOpponents.at(j));
                    constraint = constraint & (dist2Opp > autodiff::TermBuilder::constant(650 * 650));
                }
                //avoid other blockers and prefer block positions with a distance of 2m (to not block the same opponents)
                for (int j = k + 1; j < blocker.size(); j++)
                {
                    auto distBlockBlock = ConstraintBuilder::distanceSqr(blocker.at(k), blocker.at(j));
                    constraint = constraint & distBlockBlock > autodiff::TermBuilder::constant(800 * 800);
                    util = util + 5 * make_shared < autodiff::Min
                            > (autodiff::TermBuilder::constant(2000 * 2000), distBlockBlock)
                                    / autodiff::TermBuilder::constant(2000 * 2000 * blocker.size());
                }
            }
        }
        //lazy utility
        vector < shared_ptr < TVec >> realRobotPosesTVec;
        for (int i = 0; i < robotPositions.size(); i++)
        {
          auto pos = robotPositions.at(i);
          if (pos != nullptr)
              realRobotPosesTVec.push_back(make_shared < TVec > (initializer_list<double> {pos->x, pos->y}));
          else
              realRobotPosesTVec.push_back(make_shared < TVec > (initializer_list<double> {0.0, 0.0}));
        }
        util = util + msl::MSLConstraintBuilder::lazyUtil(realRobotPosesTVec, poses);
        c->setConstraint(dynamic_pointer_cast < alica::SolverTerm > (constraint));
        c->setUtility(dynamic_pointer_cast < alica::SolverTerm > (util));
        cout << "666" << endl;
        /*PROTECTED REGION END*/
    }

// State: GrabBall

// State: GrabBall

// State: Align

// State: Align

// State: Pass

// State: Pass

// State: Receive

// State: Receive

// State: Success

// State: Success

// State: Block

// State: Block

// State: Defend

// State: Defend

// State: SpatialDefend

// State: SpatialDefend

// State: Align

// State: Align

}
