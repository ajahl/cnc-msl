/*
 * ICalibration.h
 *
 *  Created on: Dec 14, 2016
 *      Author: cn
 */

#ifndef AUTOGENERATED_INCLUDE_PLANS_DRIBBLECALIBRATION_BEHAVIOURS_INTERFACES_ICALIBRATION_H_
#define AUTOGENERATED_INCLUDE_PLANS_DRIBBLECALIBRATION_BEHAVIOURS_INTERFACES_ICALIBRATION_H_

//#include "Plans/DribbleCalibration/Container/DribbleCalibrationContainer.h"
#include "Plans/DribbleCalibration/Container/MovementContainer.h"

class ICalibration
{
public:
//	virtual ~ICalibration();
	MovementContainer mCon;
//	DribbleCalibrationContainer dcc;

	virtual MotionControl move(int trans) = 0;
	virtual void adaptParams() = 0;
	virtual void writeConfigParameters() = 0;
};



#endif /* AUTOGENERATED_INCLUDE_PLANS_DRIBBLECALIBRATION_BEHAVIOURS_INTERFACES_ICALIBRATION_H_ */
