#include "Plans/Standards/Opponent/Penalty/OppInGamePenalty1466968232004.h"
using namespace alica;
/*PROTECTED REGION ID(eph1466968232004) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:OppInGamePenalty

    //Check of RuntimeCondition - (Name): NewRuntimeCondition, (ConditionString): , (Comment) :  

    /* 
     * Available Vars:
     */
    bool RunTimeCondition1466975666362::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1466975666362) ENABLED START*/
        return true;
        /*PROTECTED REGION END*/
    }

    /* generated comment
     
     Task: AttackSupport  -> EntryPoint-ID: 1466968232006

     Task: Attack  -> EntryPoint-ID: 1466975602577

     Task: Block  -> EntryPoint-ID: 1466975645495

     */
    shared_ptr<UtilityFunction> UtilityFunction1466968232004::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1466968232004) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

//State: Pos4Rebounce in Plan: OppInGamePenalty

//State: Pos4Intercept in Plan: OppInGamePenalty

//State: Block in Plan: OppInGamePenalty

}
