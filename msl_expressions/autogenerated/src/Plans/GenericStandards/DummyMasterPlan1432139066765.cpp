#include "Plans/GenericStandards/DummyMasterPlan1432139066765.h"
using namespace alica;
/*PROTECTED REGION ID(eph1432139066765) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:DummyMasterPlan

    /* generated comment
     
     Task: Blocker  -> EntryPoint-ID: 1432139066767

     */
    shared_ptr<UtilityFunction> UtilityFunction1432139066765::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1432139066765) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

//State: NewState in Plan: DummyMasterPlan

}
