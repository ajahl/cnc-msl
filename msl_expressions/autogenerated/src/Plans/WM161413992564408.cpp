#include "Plans/WM161413992564408.h"
using namespace alica;
/*PROTECTED REGION ID(eph1413992564408) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
//Plan:WM16

/* generated comment
 
 Task: DefaultTask  -> EntryPoint-ID: 1413992564410

 */
shared_ptr<UtilityFunction> UtilityFunction1413992564408::getUtilityFunction(Plan* plan)
{
  /*PROTECTED REGION ID(1413992564408) ENABLED START*/

  shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
  return defaultFunction;

  /*PROTECTED REGION END*/
}

//State: Init in Plan: WM16

/*
 *		
 * Transition:
 *   - Name: , ConditionString: , Comment :  
 *
 * Plans in State: 				
 *   - Plan - (Name): StopDefault, (PlanID): 1413992626194 
 *
 * Tasks: 
 *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
 *
 * States:
 *   - Init (1413992564409)
 *   - Drive (1413992572149)
 *   - Dribble (1414752333556)
 *
 * Vars:
 */
bool TransitionCondition1413992578046::evaluate(shared_ptr<RunningPlan> rp)
{
  /*PROTECTED REGION ID(1413992575757) ENABLED START*/
  return true;
  /*PROTECTED REGION END*/

}

//State: Drive in Plan: WM16

/*
 *		
 * Transition:
 *   - Name: MISSING_NAME, ConditionString: , Comment :  
 *
 * Plans in State: 				
 *   - Plan - (Name): DriveForwardDefault, (PlanID): 1414427354149 
 *
 * Tasks: 
 *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
 *
 * States:
 *   - Init (1413992564409)
 *   - Drive (1413992572149)
 *   - Dribble (1414752333556)
 *
 * Vars:
 */
bool TransitionCondition1414752354525::evaluate(shared_ptr<RunningPlan> rp)
{
  /*PROTECTED REGION ID(1414752349075) ENABLED START*/
	pair<double,double> alloBallPos = wm->getBallPosition();
	tuple<double, double, double> ownPos= wm->getOwnPosition();
	pair<double, double> egoBallPos = wm->allo2Ego(alloBallPos, ownPos);

	if (fabs(egoBallPos.first) <= 150 && fabs(egoBallPos.second) <= 150) {
		return true;
	} else {
		return false;
	}
  /*PROTECTED REGION END*/

}

//State: Dribble in Plan: WM16

/*
 *		
 * Transition:
 *   - Name: MISSING_NAME, ConditionString: , Comment :  
 *
 * Plans in State: 				
 *   - Plan - (Name): DribbleToPointDefault, (PlanID): 1414752423981 
 *
 * Tasks: 
 *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
 *
 * States:
 *   - Init (1413992564409)
 *   - Drive (1413992572149)
 *   - Dribble (1414752333556)
 *
 * Vars:
 */
bool TransitionCondition1414769686605::evaluate(shared_ptr<RunningPlan> rp)
{
  /*PROTECTED REGION ID(1414769683132) ENABLED START*/
	pair<double,double> alloBallPos = wm->getBallPosition();
	tuple<double, double, double> ownPos= wm->getOwnPosition();
	pair<double, double> egoBallPos = wm->allo2Ego(alloBallPos, ownPos);

	if (fabs(egoBallPos.first) >= 300 && fabs(egoBallPos.second) >= 300) {
		return true;
	} else {
		return false;
	}
  /*PROTECTED REGION END*/

}

}