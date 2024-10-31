/*
 * Timer.c
 *
 *  Created on: Oct 28, 2024
 *      Author: HP WORK
 */

#include "Timer.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	timer_run();
	button_reading();
}

//----------------------------------------------
// Funciton for timing task
//----------------------------------------------
// Set Timer for count 1 secons
uint8_t Sec_counter;
uint8_t Sec_flag = 0;
uint8_t TIMER_CYCLE = 10;

void setTimerSec(int duration){
	Sec_counter = duration / TIMER_CYCLE;
	Sec_flag = 0;
}

// Set Timer for scan LED7SEG
uint8_t Seg_counter;
uint8_t Seg_flag = 0;
void setTimerScan7Seg(int duration){
	Seg_counter = duration / TIMER_CYCLE;
	Seg_flag = 0;
}

// Set Timer for blinky led 2Hz
uint8_t Blink_counter;
uint8_t Blinky_flag = 0;
void setTimerBlinky(int duration){
	Blink_counter = duration / TIMER_CYCLE;
	Blinky_flag = 0;
}

// Timer function
void timer_run(){
	if (!(--Sec_counter)){
		Sec_flag = 1;
	}
	if (!(--Seg_counter)){
		Seg_flag = 1;
	}
	if (!(--Blink_counter)){
		Blinky_flag = 1;
	}
}
