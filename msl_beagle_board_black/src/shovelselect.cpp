/*
 * shovelselect.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: Lukas Will
 */

#include "shovelselect.h"

using namespace BlackLib;

	ShovelSelect::ShovelSelect(pwmName pwm_P) {
		pwm = new BlackPWM(pwm_P);

		pwm->setPeriodTime(period, nanosecond);
		pwm->setSpaceRatioTime(0, nanosecond);
		pwm->setRunState(stop);

		enabled = false;
	}

	ShovelSelect::~ShovelSelect() {
		delete pwm;
	}

	bool ShovelSelect::checkTimeout(timeval time) {
		if ((TIMEDIFFMS(time, ping) > timeout) && enabled) {
			pwm->setRunState(stop);
			enabled = false;

			return true;
		}

		return false;
	}

	bool ShovelSelect::setShovel(bool passing, timeval time_now) {
		ping = time_now;
		if (passing) {
			pwm->setSpaceRatioTime(passPWM, nanosecond);
		} else {
			pwm->setSpaceRatioTime(kickPWM, nanosecond);
		}
		if (!enabled) {
			pwm->setRunState(run);
			enabled = true;
		}

		return true;
	}

	bool ShovelSelect::setKick(int kick) {
		if ((kick > 1000) && (kick < 2000)) {
			kickPWM = kick * 1000;
			return true;
		} else {
			return false;
		}
	}

	bool ShovelSelect::setPass(int pass) {
		if ((pass > 1000) && (pass < 2000)) {
			passPWM = pass * 1000;
			return true;
		} else {
			return false;
		}
	}

	bool ShovelSelect::setPing(timeval time) {
		ping = time;
		return true;
	}

	bool ShovelSelect::setTimeout(int time) {
		if (time > 0) {
			timeout = time;
			return true;
		} else {
			return false;
		}
	}

