/*
 * input_processing.c
 *
 *  Created on: Oct 29, 2024
 *      Author: HP WORK
 */

#include "input_processing.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED};
enum ButtonState Button_State = BUTTON_RELEASED;

void fsm_for_input_processing(void){
	switch(Button_State){
	case BUTTON_RELEASED:
		if(is_button_pressed(0)){
			Button_State = BUTTON_PRESSED;
		}
		break;
	case BUTTON_PRESSED:
		if(!is_button_pressed(0)){
			Button_State = BUTTON_RELEASED;
		}
		break;
	}
}
