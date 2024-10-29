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
