/*
 * input_processing.c
 *
 *  Created on: Oct 29, 2024
 *      Author: HP WORK
 */

#include "input_processing.h"

enum ButtonState Button_State[4] = {BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED};
enum ButtonState Button_State_Temp[4] = {BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED};
uint8_t Actual_Button_State[4] = {0, 0, 0, 0};

void fsm_for_input_processing(void){
    for(int i = 0; i < 4; i++) {
        switch(Button_State[i]){
            case BUTTON_RELEASED:
                if(is_button_pressed(i)){
                    Button_State[i] = BUTTON_PRESSED;
                }
                break;
            case BUTTON_PRESSED:
                if(!is_button_pressed(i)){
                    Button_State[i] = BUTTON_RELEASED;
                }
                break;
        }
        if((Button_State_Temp[i] == BUTTON_RELEASED) && (Button_State[i] == BUTTON_PRESSED)) {
        	Actual_Button_State[i] = 1;
        }
        else {
        	Actual_Button_State[i] = 0;
        }
        Button_State_Temp[i] = Button_State[i];
    }
}
