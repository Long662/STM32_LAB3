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

extern enum ButtonState{BUTTON_RELEASED = 0, BUTTON_PRESSED = 1};
extern enum ButtonState Button1_State;
extern enum ButtonState Button2_State;
extern enum ButtonState Button3_State;

void fsm_for_input_processing(void);

#endif /* INC_INPUT_PROCESSING_H_ */
