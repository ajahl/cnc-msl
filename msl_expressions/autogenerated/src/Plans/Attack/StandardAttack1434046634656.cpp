#include "Plans/Attack/StandardAttack1434046634656.h"
using namespace alica;
/*PROTECTED REGION ID(eph1434046634656) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:StandardAttack

    /* generated comment
     
     Task: Attack  -> EntryPoint-ID: 1434046634658

     */
    shared_ptr<UtilityFunction> UtilityFunction1434046634656::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1434046634656) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: GetBall in Plan: StandardAttack

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : haveBall 
     *
     * Plans in State: 				
     *   - Plan - (Name): GetBallDefault, (PlanID): 1414840399972 				
     *   - Plan - (Name): DribbleControlNoBall, (PlanID): 1450175539163 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434046634658)
     *
     * States:
     *   - GetBall (1434046634657)
     *   - Duel (1434048406725)
     *   - HaveBall (1434048705508)
     *   - LostBall (1434715893346)
     *   - SideLineGetBall (1450175617600)
     *   - AdvanceAfterPass (1450175887984)
     *
     * Vars:
     */
    bool TransitionCondition1434048722207::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434048720937) ENABLED START*/
        return wm->ball.haveBall();
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : doesnt see ball || the opponent in ballpossesion 
     *
     * Plans in State: 				
     *   - Plan - (Name): GetBallDefault, (PlanID): 1414840399972 				
     *   - Plan - (Name): DribbleControlNoBall, (PlanID): 1450175539163 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434046634658)
     *
     * States:
     *   - GetBall (1434046634657)
     *   - Duel (1434048406725)
     *   - HaveBall (1434048705508)
     *   - LostBall (1434715893346)
     *   - SideLineGetBall (1450175617600)
     *   - AdvanceAfterPass (1450175887984)
     *
     * Vars:
     */
    bool TransitionCondition1434716048353::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434716047438) ENABLED START*/
        return wm->ball.getEgoBallPosition() == nullptr || wm->game.getGameState() == msl::GameState::OppBallPossession;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Ball at sideline and not behind ball and no opponent near Ball 
     *
     * Plans in State: 				
     *   - Plan - (Name): GetBallDefault, (PlanID): 1414840399972 				
     *   - Plan - (Name): DribbleControlNoBall, (PlanID): 1450175539163 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434046634658)
     *
     * States:
     *   - GetBall (1434046634657)
     *   - Duel (1434048406725)
     *   - HaveBall (1434048705508)
     *   - LostBall (1434715893346)
     *   - SideLineGetBall (1450175617600)
     *   - AdvanceAfterPass (1450175887984)
     *
     * Vars:
     */
    bool TransitionCondition1450175866027::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1450175864724) ENABLED START*/
        double threshold = 400;
        auto ball = wm->ball.getAlloBallPosition();
        if (ball == nullptr)
            return false;
        if (abs(ball->y) < msl::MSLFootballField::FieldWidth / 2 - threshold
                || abs(ball->x) < msl::MSLFootballField::FieldLength / 2 - threshold)
            return false;

        auto obs = wm->robots.opponents.getOpponentsAlloClustered();
        if (obs == nullptr)
            return false;

        double minDist = 100000000000000;
        for (auto& opp : *obs)
        {
            double temp = opp->distanceTo(ball);
            if (temp < minDist)
            {
                minDist = temp;
            }
        }
        return obs->size() > 0 && minDist < 1200;

        /*PROTECTED REGION END*/

    }

    //State: Duel in Plan: StandardAttack

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : haveball && enemy not close 
     *
     * Plans in State: 				
     *   - Plan - (Name): DuelDefault, (PlanID): 1450178707835 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434046634658)
     *
     * States:
     *   - GetBall (1434046634657)
     *   - Duel (1434048406725)
     *   - HaveBall (1434048705508)
     *   - LostBall (1434715893346)
     *   - SideLineGetBall (1450175617600)
     *   - AdvanceAfterPass (1450175887984)
     *
     * Vars:
     */
    bool TransitionCondition1434048737070::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434048734889) ENABLED START*/
        double distance = numeric_limits<double>::max();
        auto obs = wm->obstacles.getEgoVisionObstaclePoints();
        if (obs == nullptr)
        {
            return wm->ball.haveBall();
        }
        shared_ptr < geometry::CNPoint2D > ball = wm->ball.getEgoBallPosition();
        if (ball == nullptr)
        {
            return false;
        }
        double temp;
        for (int i = 0; i < obs->size(); i++)
        {
            temp = obs->at(i)->distanceTo(ball);
            if (temp < distance)
            {
                distance = temp;
            }
        }
        return wm->ball.haveBall() && distance > 1200;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : ballpos == nullptr  
     *
     * Plans in State: 				
     *   - Plan - (Name): DuelDefault, (PlanID): 1450178707835 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434046634658)
     *
     * States:
     *   - GetBall (1434046634657)
     *   - Duel (1434048406725)
     *   - HaveBall (1434048705508)
     *   - LostBall (1434715893346)
     *   - SideLineGetBall (1450175617600)
     *   - AdvanceAfterPass (1450175887984)
     *
     * Vars:
     */
    bool TransitionCondition1457687428316::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1457687426425) ENABLED START*/
        return wm->ball.getEgoBallPosition() == nullptr || !wm->ball.haveBall();
        /*PROTECTED REGION END*/

    }

    //State: HaveBall in Plan: StandardAttack

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : lostBall 
     *
     * Plans in State: 				
     *   - Plan - (Name): PassPlay, (PlanID): 1436268896671 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434046634658)
     *
     * States:
     *   - GetBall (1434046634657)
     *   - Duel (1434048406725)
     *   - HaveBall (1434048705508)
     *   - LostBall (1434715893346)
     *   - SideLineGetBall (1450175617600)
     *   - AdvanceAfterPass (1450175887984)
     *
     * Vars:
     */
    bool TransitionCondition1434048723635::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434048722503) ENABLED START*/
        return !wm->ball.haveBall();
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : haveBall && enemy close 
     *
     * Plans in State: 				
     *   - Plan - (Name): PassPlay, (PlanID): 1436268896671 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434046634658)
     *
     * States:
     *   - GetBall (1434046634657)
     *   - Duel (1434048406725)
     *   - HaveBall (1434048705508)
     *   - LostBall (1434715893346)
     *   - SideLineGetBall (1450175617600)
     *   - AdvanceAfterPass (1450175887984)
     *
     * Vars:
     */
    bool TransitionCondition1434048731181::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434048729645) ENABLED START*/
        double distance = numeric_limits<double>::max();
        auto obs = wm->obstacles.getEgoVisionObstaclePoints();
        if (obs == nullptr)
        {
            return wm->ball.haveBall();
        }
        shared_ptr < geometry::CNPoint2D > ball = wm->ball.getEgoBallPosition();
        if (ball == nullptr)
        {
            return false;
        }
        double temp;
        for (int i = 0; i < obs->size(); i++)
        {
            temp = obs->at(i)->distanceTo(ball);
            if (temp < distance)
            {
                distance = temp;
            }
        }
        return wm->ball.haveBall() && distance < 1200;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : (doesnt see ball || the opponent in ball possesion) && wm->whiteBoard.getPassMsg() != nullptr 
     *
     * Plans in State: 				
     *   - Plan - (Name): PassPlay, (PlanID): 1436268896671 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434046634658)
     *
     * States:
     *   - GetBall (1434046634657)
     *   - Duel (1434048406725)
     *   - HaveBall (1434048705508)
     *   - LostBall (1434715893346)
     *   - SideLineGetBall (1450175617600)
     *   - AdvanceAfterPass (1450175887984)
     *
     * Vars:
     */
    bool TransitionCondition1434716050319::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434716049424) ENABLED START*/
        return (wm->ball.getEgoBallPosition() == nullptr || wm->game.getGameState() == msl::GameState::OppBallPossession)
                && wm->whiteBoard.getPassMsg() != nullptr;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : not HaveBallDribble(true) && PassMsg!=null 
     *
     * Plans in State: 				
     *   - Plan - (Name): PassPlay, (PlanID): 1436268896671 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434046634658)
     *
     * States:
     *   - GetBall (1434046634657)
     *   - Duel (1434048406725)
     *   - HaveBall (1434048705508)
     *   - LostBall (1434715893346)
     *   - SideLineGetBall (1450175617600)
     *   - AdvanceAfterPass (1450175887984)
     *
     * Vars:
     */
    bool TransitionCondition1450175931490::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1450175926476) ENABLED START*/
        return !wm->ball.haveBall() && wm->whiteBoard.getPassMsg() != nullptr;
        /*PROTECTED REGION END*/

    }

    //State: LostBall in Plan: StandardAttack

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : found ball 
     *
     * Plans in State: 				
     *   - Plan - (Name): WanderDefault, (PlanID): 1434716230628 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434046634658)
     *
     * States:
     *   - GetBall (1434046634657)
     *   - Duel (1434048406725)
     *   - HaveBall (1434048705508)
     *   - LostBall (1434715893346)
     *   - SideLineGetBall (1450175617600)
     *   - AdvanceAfterPass (1450175887984)
     *
     * Vars:
     */
    bool TransitionCondition1434716049299::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434716048579) ENABLED START*/
        return wm->ball.getEgoBallPosition() != nullptr;
        /*PROTECTED REGION END*/

    }

    //State: SideLineGetBall in Plan: StandardAttack

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : SideLineGetBall2GetBall: Ball not at sideline or Fail or opponent near Ball || SideLineGetBall2ApproachBall: Success || dont see the ball 
     *
     * Plans in State: 				
     *   - Plan - (Name): DribbleControlNoBall, (PlanID): 1450175539163 				
     *   - Plan - (Name): FetchFromSideLineDefault, (PlanID): 1450175679178 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434046634658)
     *
     * States:
     *   - GetBall (1434046634657)
     *   - Duel (1434048406725)
     *   - HaveBall (1434048705508)
     *   - LostBall (1434715893346)
     *   - SideLineGetBall (1450175617600)
     *   - AdvanceAfterPass (1450175887984)
     *
     * Vars:
     */
    bool TransitionCondition1450175867019::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1450175866364) ENABLED START*/
        if (rp->anyChildrenStatus(PlanStatus::Failed))
            return true;
        double threshold = 500;
        auto ball = wm->ball.getAlloBallPosition();
        if (ball == nullptr)
            return true;
        if (abs(ball->y) < msl::MSLFootballField::FieldWidth / 2 - threshold
                || abs(ball->x) < msl::MSLFootballField::FieldLength / 2 - threshold)
            return true;
        /*PROTECTED REGION END*/

    }

    //State: AdvanceAfterPass in Plan: StandardAttack

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : KickSomeHowFailed -> We need to reaproach the ball 
     *
     * Plans in State: 				
     *   - Plan - (Name): AdvancdeSimplePassDefault, (PlanID): 1450176216458 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434046634658)
     *
     * States:
     *   - GetBall (1434046634657)
     *   - Duel (1434048406725)
     *   - HaveBall (1434048705508)
     *   - LostBall (1434715893346)
     *   - SideLineGetBall (1450175617600)
     *   - AdvanceAfterPass (1450175887984)
     *
     * Vars:
     */
    bool TransitionCondition1450175926118::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1450175921044) ENABLED START*/
        double kickVelocity = wm->kicker.getPassVelocity(wm->kicker.getKickConstrolMsg()->power) / 1000.0;
        double nsSinceKick = (double)(rp->getStateStartTime());
        double expectedBallTravelDistance = kickVelocity * (nsSinceKick / 1000000);

        auto egoBall = wm->ball.getEgoBallPosition();
        if (egoBall == nullptr)
            return true;
        double ballDistance = egoBall->length();
        return (isTimeOut(150 * 1000000, rp->getStateStartTime(), rp) && ballDistance < expectedBallTravelDistance / 2.0)
                || isTimeOut(1500 * 1000000, rp->getStateStartTime(), rp);

        return false;
        /*PROTECTED REGION END*/

    }

}
