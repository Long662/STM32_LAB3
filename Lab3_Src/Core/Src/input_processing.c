/*
 * input_processing.c
 *
 *  Created on: Oct 29, 2024
 *      Author: HP WORK
 */

#include "input_processing.h"

enum ButtonState Button1_State = BUTTON_RELEASED;
enum ButtonState Button2_State = BUTTON_RELEASED;
enum ButtonState Button3_State = BUTTON_RELEASED;

void fsm_for_input_processing(void){
	switch(Button1_State | Button2_State | Button3_State){
	case BUTTON_RELEASED:
		if(is_button_pressed(0)){
			Button1_State = BUTTON_PRESSED;
		}
		else if(is_button_pressed(1)){
			Button2_State = BUTTON_PRESSED;
		}
		else if(is_button_pressed(2)){
			Button3_State = BUTTON_PRESSED;
		}
		break;
	case BUTTON_PRESSED:
		if(!is_button_pressed(0)){
			Button1_State = BUTTON_RELEASED;
		}
		else if(!is_button_pressed(1)){
			Button2_State = BUTTON_RELEASED;
		}
		else if(!is_button_pressed(2)){
			Button3_State = BUTTON_RELEASED;
		}
		break;
	}
}
