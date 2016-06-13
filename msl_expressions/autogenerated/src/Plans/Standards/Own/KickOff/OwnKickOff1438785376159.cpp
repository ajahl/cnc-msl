#include "Plans/Standards/Own/KickOff/OwnKickOff1438785376159.h"
using namespace alica;
/*PROTECTED REGION ID(eph1438785376159) ENABLED START*/ //Add additional using directives here
#include "engine/Assignment.h"
#include "PriorityList.h"
#include "engine/model/Plan.h"
#include "engine/collections/StateCollection.h"
#include <MSLWorldModel.h>
#include <Ball.h>
#include <Game.h>
#include <Rules.h>
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:OwnKickOff

    /* generated comment
     
     Task: ExecuteStandard  -> EntryPoint-ID: 1438785376161

     Task: ReceiveStandard  -> EntryPoint-ID: 1438785392109

     Task: Defend  -> EntryPoint-ID: 1444834088607

     */
    shared_ptr<UtilityFunction> UtilityFunction1438785376159::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1438785376159) ENABLED START*/
        vector<long> entryPoints;

        entryPoints.push_back(1438785376161); // ExecuteStandard
        entryPoints.push_back(1438785392109); // ReceiveStandard
        entryPoints.push_back(1444834088607); // Defend

        PriorityList* us = new PriorityList(2.0, "OtherPlan", 2, entryPoints);
        list<USummand*> utilSummands;
        utilSummands.push_back(us);
        shared_ptr < UtilityFunction > function = make_shared < UtilityFunction
                > ("OtherPlanUtilTest", utilSummands, 0.1, 0.2, plan);
        return function;
        /*PROTECTED REGION END*/
    }

    //State: PosExec in Plan: OwnKickOff

    /*
     *		
     * Transition:
     *   - Name: PosExec2GrabBall, ConditionString: , Comment : From PosExec 2 GrabBall State: If we reached the executor position and start signal was sent. 
     *
     * Plans in State: 				
     *   - Plan - (Name): PositionExecutorDefault, (PlanID): 1438790487994 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1438785376161)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1438785392109)
     *   - Defend (1225115406909) (Entrypoint: 1444834088607)
     *
     * States:
     *   - PosExec (1438785376160)
     *   - PosRecv (1438785501838)
     *   - GrabBall (1440675376134)
     *   - Pass (1440772305591)
     *   - Receive (1440772454611)
     *   - Success (1440772500050)
     *   - Dummy (1441811642575)
     *   - PosDef (1444834163414)
     *
     * Vars:
     */
    bool TransitionCondition1440675385644::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1440675383814) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success) && wm->game->checkSituation(msl::Situation::Start);
        /*PROTECTED REGION END*/

    }

    //State: PosRecv in Plan: OwnKickOff

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : receiver aligned and executor has shot 
     *
     * Plans in State: 				
     *   - Plan - (Name): PositionReceiverDefault, (PlanID): 1439379352605 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1438785376161)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1438785392109)
     *   - Defend (1225115406909) (Entrypoint: 1444834088607)
     *
     * States:
     *   - PosExec (1438785376160)
     *   - PosRecv (1438785501838)
     *   - GrabBall (1440675376134)
     *   - Pass (1440772305591)
     *   - Receive (1440772454611)
     *   - Success (1440772500050)
     *   - Dummy (1441811642575)
     *   - PosDef (1444834163414)
     *
     * Vars:
     */
    bool TransitionCondition1440772553737::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1440772549851) ENABLED START*/

        //TODO bedingung erweitern, um schneller zu erkennen, dass der executor geschossen hat
        // über egoBallVelocity (negatives x, größer als bestimmter wert)
        return rp->anyChildrenStatus(PlanStatus::Success)
                && (rp->getAssignment()->getRobotStateMapping()->getRobotsInState(1441811642575).size() > 0
                        || (rp->getAssignment()->getRobotStateMapping()->getRobotsInState(1440675376134).size() > 0
                                && wm->ball->getEgoBallVelocity()->x > 500));
        /*PROTECTED REGION END*/

    }

    //State: GrabBall in Plan: OwnKickOff

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : success 
     *
     * Plans in State: 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 				
     *   - Plan - (Name): StandardAlignAndGrabOwnKickOff, (PlanID): 1459456566595 				
     *   - Plan - (Name): StandardActuateDefault, (PlanID): 1435766278023 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1438785376161)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1438785392109)
     *   - Defend (1225115406909) (Entrypoint: 1444834088607)
     *
     * States:
     *   - PosExec (1438785376160)
     *   - PosRecv (1438785501838)
     *   - GrabBall (1440675376134)
     *   - Pass (1440772305591)
     *   - Receive (1440772454611)
     *   - Success (1440772500050)
     *   - Dummy (1441811642575)
     *   - PosDef (1444834163414)
     *
     * Vars:
     */
    bool TransitionCondition1440772549250::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1440772545631) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: Pass in Plan: OwnKickOff

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : lost ball 
     *
     * Plans in State: 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 				
     *   - Plan - (Name): StandardPassDefault, (PlanID): 1435760175843 				
     *   - Plan - (Name): StandardActuateDefault, (PlanID): 1435766278023 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1438785376161)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1438785392109)
     *   - Defend (1225115406909) (Entrypoint: 1444834088607)
     *
     * States:
     *   - PosExec (1438785376160)
     *   - PosRecv (1438785501838)
     *   - GrabBall (1440675376134)
     *   - Pass (1440772305591)
     *   - Receive (1440772454611)
     *   - Success (1440772500050)
     *   - Dummy (1441811642575)
     *   - PosDef (1444834163414)
     *
     * Vars:
     */
    bool TransitionCondition1440772443709::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1440772442289) ENABLED START*/
        return !wm->ball->haveBall() && !rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : executor finished pass 
     *
     * Plans in State: 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 				
     *   - Plan - (Name): StandardPassDefault, (PlanID): 1435760175843 				
     *   - Plan - (Name): StandardActuateDefault, (PlanID): 1435766278023 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1438785376161)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1438785392109)
     *   - Defend (1225115406909) (Entrypoint: 1444834088607)
     *
     * States:
     *   - PosExec (1438785376160)
     *   - PosRecv (1438785501838)
     *   - GrabBall (1440675376134)
     *   - Pass (1440772305591)
     *   - Receive (1440772454611)
     *   - Success (1440772500050)
     *   - Dummy (1441811642575)
     *   - PosDef (1444834163414)
     *
     * Vars:
     */
    bool TransitionCondition1441811702176::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1441811700499) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: Receive in Plan: OwnKickOff

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : any child success 
     *
     * Plans in State: 				
     *   - Plan - (Name): InterceptDefault, (PlanID): 1458757193843 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1438785376161)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1438785392109)
     *   - Defend (1225115406909) (Entrypoint: 1444834088607)
     *
     * States:
     *   - PosExec (1438785376160)
     *   - PosRecv (1438785501838)
     *   - GrabBall (1440675376134)
     *   - Pass (1440772305591)
     *   - Receive (1440772454611)
     *   - Success (1440772500050)
     *   - Dummy (1441811642575)
     *   - PosDef (1444834163414)
     *
     * Vars:
     */
    bool TransitionCondition1440772876913::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1440772873418) ENABLED START*/
        return this->isTimeOut(this->rules->getStandbyTime()*0.75, rp->getStateStartTime(), rp);
        //return rp->anyChildrenStatus(PlanStatus::Success);
        //return rp->anyChildrenStatus(PlanStatus::Failed) || (this->isTimeOut(2000000000, rp->getPlanStartTime(), rp) && wm->whiteBoard.getPassMsg()==nullptr);
        /*PROTECTED REGION END*/

    }

//State: Success in Plan: OwnKickOff

//State: Dummy in Plan: OwnKickOff

//State: PosDef in Plan: OwnKickOff

}
