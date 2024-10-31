/*
 * Lab3_Process.h
 *
 *  Created on: Oct 22, 2024
 *      Author: HP WORK
 */

#ifndef INC_LAB3_PROCESS_H_
#define INC_LAB3_PROCESS_H_

#include "main.h"
#include "Timer.h"
#include "led_display.h"
#include "input_processing.h"

void setTimerSec(int duration);
void timer_run();

void Lab3_FSM_Traffic(void);
void Lab3_FSM_Input_Process(void);

void Mode_1(void);
void Mode_2(void);
void Mode_3(void);
void Mode_4(void);

#endif /* INC_LAB3_PROCESS_H_ */
