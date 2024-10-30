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
enum ButtonState Button1_State_Temp = BUTTON_RELEASED;
enum ButtonState Button2_State_Temp = BUTTON_RELEASED;
enum ButtonState Button3_State_Temp = BUTTON_RELEASED;

void fsm_for_input_processing(void){
	// Switch Button1
	switch(Button1_State){
	case BUTTON_RELEASED:
		if(is_button_pressed(0)){
			Button1_State = BUTTON_PRESSED;
		}
		break;
	case BUTTON_PRESSED:
		if(!is_button_pressed(0)){
			Button1_State = BUTTON_RELEASED;
		}
		break;
	}
	// Switch Button2
	switch(Button2_State){
	case BUTTON_RELEASED:
		if(is_button_pressed(1)){
			Button2_State = BUTTON_PRESSED;
		}
		break;
	case BUTTON_PRESSED:
		if(!is_button_pressed(1)){
			Button2_State = BUTTON_RELEASED;
		}
		break;
	}
	// Switch Button3
	switch(Button3_State){
	case BUTTON_RELEASED:
		if(is_button_pressed(2)){
			Button3_State = BUTTON_PRESSED;
		}
		break;
	case BUTTON_PRESSED:
		if(!is_button_pressed(2)){
			Button3_State = BUTTON_RELEASED;
		}
		break;
	}
}
