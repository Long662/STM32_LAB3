/*
 * led_display.h
 *
 *  Created on: Oct 22, 2024
 *      Author: HP WORK
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"
#include "MyLED7SEG.h"

void Lab3_Led_Init(void);

void Enable_led7seg(int num);
void Update_Display(uint8_t main, uint8_t sub, uint8_t mode);
void Scan_Display(uint8_t index, uint8_t mode);


#endif /* INC_LED_DISPLAY_H_ */
