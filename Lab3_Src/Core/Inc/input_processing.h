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
//extern enum ButtonState Button1_State;
//extern enum ButtonState Button2_State;
//extern enum ButtonState Button3_State;
//extern enum ButtonState Button1_State_Temp;
//extern enum ButtonState Button2_State_Temp;
//extern enum ButtonState Button3_State_Temp;
extern enum ButtonState Button_State[4];
extern enum ButtonState Button_State_Temp[4];


void fsm_for_input_processing(void);

#endif /* INC_INPUT_PROCESSING_H_ */
