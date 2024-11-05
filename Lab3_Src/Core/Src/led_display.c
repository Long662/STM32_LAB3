/*
 * led_display.c
 *
 *  Created on: Oct 22, 2024
 *      Author: HP WORK
 */

#include "led_display.h"
//-----------------------------------------------------------------------
// Init traffic Led and 7seg
//-----------------------------------------------------------------------
LED7SEG_Name SEG1;
LED7SEG_Name SEG2;

void Lab3_Led_Init(void){
	// Turn off all traffic led
	HAL_GPIO_WritePin(GPIOA, RED_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, YELLOW_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GREEN_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, RED_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, YELLOW_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GREEN_1_Pin, GPIO_PIN_SET);

	// Turn off 4 led 7SEG
	HAL_GPIO_WritePin(GPIOA, EN1_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, EN1_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, EN2_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, EN2_2_Pin, GPIO_PIN_SET);

	// Turn off LED DEBUG
	HAL_GPIO_WritePin(LED_DEBUG_GPIO_Port, LED_DEBUG_Pin, GPIO_PIN_SET);

	// Init 2 led 7seg for 2 road
	LED7SEG_Init(&SEG1,	GPIOB, SEG1_0_Pin,
						GPIOB, SEG1_1_Pin,
						GPIOB, SEG1_2_Pin,
						GPIOB, SEG1_3_Pin,
						GPIOB, SEG1_4_Pin,
						GPIOB, SEG1_5_Pin,
						GPIOB, SEG1_6_Pin);
	LED7SEG_Init(&SEG2,	GPIOB, SEG2_0_Pin,
						GPIOB, SEG2_1_Pin,
						GPIOB, SEG2_2_Pin,
						GPIOB, SEG2_3_Pin,
						GPIOB, SEG2_4_Pin,
						GPIOB, SEG2_5_Pin,
						GPIOB, SEG2_6_Pin);
}

//-----------------------------------------------------------------------
// Led7Seg process
//-----------------------------------------------------------------------
int Main_led_buffer[2];
int Sub_led_buffer[2];

void Update_Display(uint8_t main, uint8_t sub){
	// Update main road index
	Main_led_buffer[0] = main / 10;
	Main_led_buffer[1] = main % 10;
	// Update sub road index
	Sub_led_buffer[0] = sub / 10;
	Sub_led_buffer[1] = sub % 10;
}

void Enable_led7seg(int num){
	switch (num){
		case 0: HAL_GPIO_WritePin(EN1_1_GPIO_Port, EN1_1_Pin, RESET);
				HAL_GPIO_WritePin(EN1_2_GPIO_Port, EN1_2_Pin, SET);
				HAL_GPIO_WritePin(EN2_1_GPIO_Port, EN2_1_Pin, RESET);
				HAL_GPIO_WritePin(EN2_2_GPIO_Port, EN2_2_Pin, SET);
				break;
		case 1: HAL_GPIO_WritePin(EN1_1_GPIO_Port, EN1_1_Pin, SET);
				HAL_GPIO_WritePin(EN1_2_GPIO_Port, EN1_2_Pin, RESET);
				HAL_GPIO_WritePin(EN2_1_GPIO_Port, EN2_1_Pin, SET);
				HAL_GPIO_WritePin(EN2_2_GPIO_Port, EN2_2_Pin, RESET);
				break;
	}
}

void Scan_Display(uint8_t index, uint8_t mode) {
	Enable_led7seg(index);
	if (mode == 1){
		LED7SEG_Write(&SEG1, Main_led_buffer[index]);
		LED7SEG_Write(&SEG2, Sub_led_buffer[index]);
	}
	else {
		LED7SEG_Write(&SEG1, Main_led_buffer[index]);
		LED7SEG_Write(&SEG2, Sub_led_buffer[index]);
	}

}
