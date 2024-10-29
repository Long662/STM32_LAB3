/*
 * MyLed7Seg.h
 *
 *  Created on: Sep 22, 2024
 *      Author: HP WORK
 */
// *NOTE: This library is working only for Led 7 Segment Anode type

#ifndef SRC_LAB1_LIB_MYLED7SEG_H_
#define SRC_LAB1_LIB_MYLED7SEG_H_

#include "main.h"

typedef struct LED7SEG_struct{
	GPIO_TypeDef* SEG_A;
	uint16_t SEG_A_Pin;
	GPIO_TypeDef* SEG_B;
	uint16_t SEG_B_Pin;
	GPIO_TypeDef* SEG_C;
	uint16_t SEG_C_Pin;
	GPIO_TypeDef* SEG_D;
	uint16_t SEG_D_Pin;
	GPIO_TypeDef* SEG_E;
	uint16_t SEG_E_Pin;
	GPIO_TypeDef* SEG_F;
	uint16_t SEG_F_Pin;
	GPIO_TypeDef* SEG_G;
	uint16_t SEG_G_Pin;
} LED7SEG_Name;

void LED7SEG_Init(LED7SEG_Name* LED7SEG,	GPIO_TypeDef* SEG_A,  uint16_t SEG_A_Pin,
											GPIO_TypeDef* SEG_B,  uint16_t SEG_B_Pin,
											GPIO_TypeDef* SEG_C,  uint16_t SEG_C_Pin,
											GPIO_TypeDef* SEG_D,  uint16_t SEG_D_Pin,
											GPIO_TypeDef* SEG_E,  uint16_t SEG_E_Pin,
											GPIO_TypeDef* SEG_F,  uint16_t SEG_F_Pin,
											GPIO_TypeDef* SEG_G,  uint16_t SEG_G_Pin);

void LED7SEG_Write(LED7SEG_Name* LED7SEG, uint8_t number);

#endif /* SRC_LAB1_LIB_MYLED7SEG_H_ */
