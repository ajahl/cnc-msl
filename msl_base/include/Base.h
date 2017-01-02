/*
 * Base.h
 *
 *  Created on: 22.10.2014
 *      Author: Alex Jahl
 */

#ifndef BASE_H_
#define BASE_H_

#include <iostream>

#include "engine/AlicaEngine.h"
#include "BehaviourCreator.h"
#include "ConditionCreator.h"
#include "UtilityFunctionCreator.h"
#include "ConstraintCreator.h"

using namespace std;

namespace msl
{

	class Base
	{
	public:
		Base(string roleSetName, string masterPlanName, string roleSetDir, bool sim);
		virtual ~Base();

		void start();

		alica::AlicaEngine* ae;
		alica::BehaviourCreator* bc;
		alica::ConditionCreator* cc;
		alica::UtilityFunctionCreator* uc;
		alica::ConstraintCreator* crc;
	};

} /* namespace msl */

#endif /* BASE_H_ */
