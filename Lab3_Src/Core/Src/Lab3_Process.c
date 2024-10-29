/*
 * Lab3_Process.c
 *
 *  Created on: Oct 22, 2024
 *      Author: HP WORK
 */
//----------------------------------------------
#include "Lab3_Process.h"
//----------------------------------------------
// Timer for timing task
//----------------------------------------------
// Set Timer for count 1 secons
uint8_t Sec_counter;
uint8_t Sec_flag = 0;
uint8_t TIMER_CYCLE = 10;

void setTimerSec(int duration){
	Sec_counter = duration / TIMER_CYCLE;
	Sec_flag = 0;
}

// Set Timer for scan LED7SEG
uint8_t Seg_counter;
uint8_t Seg_flag = 0;
void setTimerScan7Seg(int duration){
	Seg_counter = duration / TIMER_CYCLE;
	Seg_flag = 0;
}

// Set Timer for blinky led 2Hz
uint8_t Blink_counter;
uint8_t Blinky_flag = 0;
void setTimerBlinky(int duration){
	Blink_counter = duration / TIMER_CYCLE;
	Blinky_flag = 0;
}

// Timer function
void timer_run(){
	if (!(--Sec_counter)){
		Sec_flag = 1;
	}
	if (!(--Seg_counter)){
		Seg_flag = 1;
	}
	if (!(--Blink_counter)){
		Blinky_flag = 1;
	}
}
//----------------------------------------------
// Mode running in LAB3
//----------------------------------------------
//**** MODE 1 ****
// Init Duration for each led in the main road (second)
uint8_t RED_Dur_count = 2;
uint8_t YELLOW_Dur_count = 2;
uint8_t GREEN_Dur_count = 2;
uint8_t Main_Dur_count = 2; // The main road will act Red first
uint8_t Sub_Dur_count = 2; // The sub road will act Green first

enum Led_state{RED, GREEN, YELLOW};
enum Led_state Main_led = RED;
enum Led_state Sub_led = GREEN;

void Mode_1(void){
	if (Sec_flag){
		HAL_GPIO_TogglePin(LED_DEBUG_GPIO_Port, LED_DEBUG_Pin);
		Main_Dur_count--;
		Sub_Dur_count--;
		// FSM for main led
		switch (Main_led) {
			case RED:
				// Main road
				HAL_GPIO_WritePin(RED_0_GPIO_Port, RED_0_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(YELLOW_0_GPIO_Port, YELLOW_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GREEN_0_GPIO_Port, GREEN_0_Pin, GPIO_PIN_SET);
				// Times to change state
				if (Main_Dur_count <= 0) {
					Main_led = GREEN;
					Main_Dur_count = GREEN_Dur_count;
				}
				break;
			case YELLOW:
				// Main road
				HAL_GPIO_WritePin(RED_0_GPIO_Port, RED_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(YELLOW_0_GPIO_Port, YELLOW_0_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GREEN_0_GPIO_Port, GREEN_0_Pin, GPIO_PIN_SET);
				// Time to change states
				if (Main_Dur_count <= 0) {
					Main_led = RED;
					Main_Dur_count = RED_Dur_count;
				}
				break;
			case GREEN:
				// Main road
				HAL_GPIO_WritePin(RED_0_GPIO_Port, RED_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(YELLOW_0_GPIO_Port, YELLOW_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GREEN_0_GPIO_Port, GREEN_0_Pin, GPIO_PIN_RESET);
				// Times to change state
				if (Main_Dur_count <= 0) {
					Main_led = YELLOW;
					Main_Dur_count = YELLOW_Dur_count;
				}
				break;
			default: // DO NOT THING
				break;
		}
		// FSM for sub led
		switch (Sub_led) {
			case RED:
				// Main road
				HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_SET);
				// Times to change state
				if (Sub_Dur_count <= 0) {
					Sub_led = GREEN;
					Sub_Dur_count = GREEN_Dur_count;
				}
				break;
			case YELLOW:
				// Main road
				HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_SET);
				// Time to change states
				if (Sub_Dur_count <= 0) {
					Sub_led = RED;
					Sub_Dur_count = RED_Dur_count;
				}
				break;
			case GREEN:
				// Main road
				HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_RESET);
				// Times to change state
				if (Sub_Dur_count <= 0) {
					Sub_led = YELLOW;
					Sub_Dur_count = YELLOW_Dur_count;
				}
				break;
			default: // DO NOT THING
				break;
		}
		Update_Display(Main_Dur_count, Sub_Dur_count);
		setTimerSec(1000);
	}
}

//**** MODE 2 ****
void Mode_2(void){
	// Turn of all traffic LED
	HAL_GPIO_WritePin(YELLOW_0_GPIO_Port, YELLOW_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN_0_GPIO_Port, GREEN_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_SET);
	// Blink red led in 2Hz
	if (Blinky_flag){
		HAL_GPIO_TogglePin(LED_DEBUG_GPIO_Port, LED_DEBUG_Pin);
		HAL_GPIO_TogglePin(RED_0_GPIO_Port, RED_0_Pin);
		HAL_GPIO_TogglePin(RED_1_GPIO_Port, RED_1_Pin);
		setTimerBlinky(500); // 500ms - 2Hz
	}
}

//**** MODE 3 ****
void Mode_3(void){
	// Turn of all traffic LED
	HAL_GPIO_WritePin(RED_0_GPIO_Port, RED_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN_0_GPIO_Port, GREEN_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_SET);
	// Blink red led in 2Hz
	if (Blinky_flag){
		HAL_GPIO_TogglePin(LED_DEBUG_GPIO_Port, LED_DEBUG_Pin);
		HAL_GPIO_TogglePin(YELLOW_0_GPIO_Port, YELLOW_0_Pin);
		HAL_GPIO_TogglePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin);
		setTimerBlinky(500); // 500ms - 2Hz
	}
}

//**** MODE 4 ****
void Mode_4(void){
	// Turn of all traffic LED
	HAL_GPIO_WritePin(YELLOW_0_GPIO_Port, YELLOW_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_0_GPIO_Port, RED_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
	// Blink red led in 2Hz
	if (Blinky_flag){
		HAL_GPIO_TogglePin(LED_DEBUG_GPIO_Port, LED_DEBUG_Pin);
		HAL_GPIO_TogglePin(GREEN_0_GPIO_Port, GREEN_0_Pin);
		HAL_GPIO_TogglePin(GREEN_1_GPIO_Port, GREEN_1_Pin);
		setTimerBlinky(500); // 500ms - 2Hz
	}
}

//----------------------------------------------
// FSM LAB3
//----------------------------------------------
uint8_t Seg_ind = 0;

void Lab3_FSM_Traffic(void){
	Mode_4();
	if (Seg_flag) {
		Scan_Display(Seg_ind);
		Seg_ind = (Seg_ind + 1) % 2;
		setTimerScan7Seg(100);
	}
}
