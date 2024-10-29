/*
 * input_reading.c
 *
 *  Created on: Oct 22, 2024
 *      Author: HP WORK
 */


#include "main.h"

#define NO_OF_BUTTONS	3

#define BUTTON_IS_PRESSED				GPIO_PIN_RESET
#define BUTTON_IS_RELEASED				GPIO_PIN_SET
// the buffer that the final result is stored after debouncing
static GPIO_PinState	buttonBuffer[NO_OF_BUTTONS];
// define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
// define pinout of button
static uint16_t Button_Pin[NO_OF_BUTTONS] = {BUTTON_1_Pin, BUTTON_2_Pin, BUTTON_3_Pin};

void button_reading(void){
	for (int i = 0; i < NO_OF_BUTTONS; i++) {
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(GPIOA, Button_Pin[i]);
		if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i]) {
			buttonBuffer[i] = debounceButtonBuffer1[i];
		}
	}
}

unsigned char is_button_pressed(uint8_t index) {
	if (index >= NO_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}
