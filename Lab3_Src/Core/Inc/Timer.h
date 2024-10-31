/*
 * Timer.h
 *
 *  Created on: Oct 28, 2024
 *      Author: HP WORK
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"
#include "input_reading.h"
#include "Lab3_process.h"

extern uint8_t Seg_flag;
extern uint8_t Blinky_flag;
extern uint8_t Sec_flag;

void setTimerSec(int duration);
void setTimerScan7Seg(int duration);
void setTimerBlinky(int duration);
void timer_run();


#endif /* INC_TIMER_H_ */
