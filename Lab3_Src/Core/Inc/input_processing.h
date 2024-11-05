/*
 * input_processing.h
 *
 *  Created on: Oct 29, 2024
 *      Author: HP WORK
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

#include "main.h"
#include "input_reading.h"

enum ButtonState{BUTTON_RELEASED = 0, BUTTON_PRESSED = 1};
enum ButtonState Button_State[4];
enum ButtonState Button_State_Temp[4];

extern uint8_t Actual_Button_State[4];

void fsm_for_input_processing(void);

#endif /* INC_INPUT_PROCESSING_H_ */
