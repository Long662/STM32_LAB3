/*
 * Lab3_Process.c
 *
 *  Created on: Oct 22, 2024
 *      Author: HP WORK
 */
//----------------------------------------------
#include "Lab3_Process.h"

//----------------------------------------------
// Mode running in LAB3
//----------------------------------------------
//**** MODE 1 ****
// Init Duration for each led in the main road (second)
uint8_t RED_Dur_count = 1;
uint8_t YELLOW_Dur_count = 1;
uint8_t GREEN_Dur_count = 1;
uint8_t Main_Dur_count = 1;
uint8_t Sub_Dur_count = 1;

enum Led_state{RED, GREEN, YELLOW};
enum Led_state Main_led = RED;
enum Led_state Sub_led = GREEN;

void Mode_1(void){
	if (Sec_flag){
		HAL_GPIO_TogglePin(LED_DEBUG_GPIO_Port, LED_DEBUG_Pin);
		Update_Display(Main_Dur_count, Sub_Dur_count);
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
		Main_Dur_count--;
		Sub_Dur_count--;
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

	// Blink yellow led in 2Hz
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

	// Blink green led in 2Hz
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
typedef void (*FSM_MODE)(void);
FSM_MODE mode[4] = {Mode_1, Mode_2, Mode_3, Mode_4};
uint8_t Mode_running = 0;
uint8_t Seg_ind;
uint8_t RED_Dur_temp = 1;
uint8_t YELLOW_Dur_temp = 1;
uint8_t GREEN_Dur_temp = 1;

void Lab3_FSM_Traffic(void){
	//-------READING INPUT AND CALL FUNCTION POINTER-------
	fsm_for_input_processing();
	mode[Mode_running]();

	//-------BUTTON ACTION-------
	// Action when button 1 is pressed
	if (Actual_Button_State[0]) {
		Mode_running++;
		if (Mode_running >= 4){
			Mode_running = 0;
			// Set Main_led and Sub_led to the first case
			Main_led = RED;
			Sub_led = GREEN;
			Main_Dur_count = RED_Dur_count;
			Sub_Dur_count = GREEN_Dur_count;
		}
	}
	// Action when button 2 is pressed
	else if (Actual_Button_State[1]) {
		switch (Mode_running){
		case 0: // Do nothing
			break;
		case 1: // increase red duration
			RED_Dur_temp = (RED_Dur_temp == 99) ? 99 : (RED_Dur_temp + 1);
			break;
		case 2: // increase yellow duration
			YELLOW_Dur_temp = (YELLOW_Dur_temp == 99) ? 99 : (YELLOW_Dur_temp + 1);
			break;
		case 3: // increase green duration
			GREEN_Dur_temp = (GREEN_Dur_temp == 99) ? 99 : (GREEN_Dur_temp + 1);
			break;
		}
	}

	// Action when button 3 is pressed
	else if (Actual_Button_State[2]) {
		switch (Mode_running){
		case 0: // Do nothing
			break;
		case 1: // increase red duration
			RED_Dur_temp = (RED_Dur_temp == 1) ? 1 : (RED_Dur_temp - 1);
			break;
		case 2: // increase yellow duration
			YELLOW_Dur_temp = (YELLOW_Dur_temp == 1) ? 1 : (YELLOW_Dur_temp - 1);
			break;
		case 3: // increase green duration
			GREEN_Dur_temp = (GREEN_Dur_temp == 1) ? 1 : (GREEN_Dur_temp - 1);
			break;
		}
	}

	// Action when button 4 is pressed
	else if (Actual_Button_State[4]) {
		switch (Mode_running){
		case 0: // Do nothing
			break;
		case 1: // set red duration
			RED_Dur_count = RED_Dur_temp;
			break;
		case 2: // set yellow duration
			YELLOW_Dur_count = YELLOW_Dur_temp;
			break;
		case 3: // set green duration
			GREEN_Dur_count = GREEN_Dur_temp;
			break;
		}
	}


	//-------DISPLAY-------
	if (Seg_flag) {
		switch(Mode_running) {
		case 0:
			break;
		case 1:
			Update_Display(RED_Dur_temp, 2);
			break;
		case 2:
			Update_Display(YELLOW_Dur_temp, 3);
			break;
		case 3:
			Update_Display(GREEN_Dur_temp, 4);
			break;
		}
		Scan_Display(Seg_ind, 2);
		Seg_ind = (Seg_ind + 1) % 2;
		setTimerScan7Seg(500);
	}
}
