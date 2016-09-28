/*
 * timer.h
 *
 *  Created on: Sep 19, 2016
 *      Author: Carpe Noctem
 */

#ifndef CNC_MSL_MSL_ELECTRONIC_BOARDS_REKICK2015_SRC_TIMER_H_
#define CNC_MSL_MSL_ELECTRONIC_BOARDS_REKICK2015_SRC_TIMER_H_

#include <avr/io.h>

#define TIMER_PRESCALER		1
#define TIMER_RES			10					// in us

extern volatile uint8_t ticks[4];
extern volatile uint16_t t16;
extern volatile uint32_t t32;
extern volatile int16_t kicker_ticks;

#endif /* CNC_MSL_MSL_ELECTRONIC_BOARDS_REKICK2015_SRC_TIMER_H_ */
