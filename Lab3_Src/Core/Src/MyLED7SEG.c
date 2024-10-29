/*
 * MyLed7Seg.c
 *
 *  Created on: Sep 22, 2024
 *      Author: HP WORK
 */

#include "MyLED7SEG.h"

char AnodeNumber[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void LED7SEG_Init(LED7SEG_Name* LED7SEG,	GPIO_TypeDef* SEG_A,  uint16_t SEG_A_Pin,
											GPIO_TypeDef* SEG_B,  uint16_t SEG_B_Pin,
											GPIO_TypeDef* SEG_C,  uint16_t SEG_C_Pin,
											GPIO_TypeDef* SEG_D,  uint16_t SEG_D_Pin,
											GPIO_TypeDef* SEG_E,  uint16_t SEG_E_Pin,
											GPIO_TypeDef* SEG_F,  uint16_t SEG_F_Pin,
											GPIO_TypeDef* SEG_G,  uint16_t SEG_G_Pin)
{
	LED7SEG->SEG_A = SEG_A;
	LED7SEG->SEG_B = SEG_B;
	LED7SEG->SEG_C = SEG_C;
	LED7SEG->SEG_D = SEG_D;
	LED7SEG->SEG_E = SEG_E;
	LED7SEG->SEG_F = SEG_F;
	LED7SEG->SEG_G = SEG_G;
	LED7SEG->SEG_A_Pin = SEG_A_Pin;
	LED7SEG->SEG_B_Pin = SEG_B_Pin;
	LED7SEG->SEG_C_Pin = SEG_C_Pin;
	LED7SEG->SEG_D_Pin = SEG_D_Pin;
	LED7SEG->SEG_E_Pin = SEG_E_Pin;
	LED7SEG->SEG_F_Pin = SEG_F_Pin;
	LED7SEG->SEG_G_Pin = SEG_G_Pin;
}

void LED7SEG_Write(LED7SEG_Name* LED7SEG, uint8_t number){
	HAL_GPIO_WritePin(LED7SEG->SEG_A, LED7SEG->SEG_A_Pin, AnodeNumber[number]&0x01?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7SEG->SEG_B, LED7SEG->SEG_B_Pin, AnodeNumber[number]&0x02?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7SEG->SEG_C, LED7SEG->SEG_C_Pin, AnodeNumber[number]&0x04?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7SEG->SEG_D, LED7SEG->SEG_D_Pin, AnodeNumber[number]&0x08?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7SEG->SEG_E, LED7SEG->SEG_E_Pin, AnodeNumber[number]&0x10?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7SEG->SEG_F, LED7SEG->SEG_F_Pin, AnodeNumber[number]&0x20?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7SEG->SEG_G, LED7SEG->SEG_G_Pin, AnodeNumber[number]&0x40?GPIO_PIN_SET:GPIO_PIN_RESET);
}
