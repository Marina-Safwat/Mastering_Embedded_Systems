/*

 * Keypad.h
 *
 *  Created on: Apr 27, 2024
 *      Author: Marina

*/

#ifndef INC_KEYPAD_H
#define INC_KEYPAD_H

#include "STM32F103x6.h"
#include "GPIO.h"

//keypad pins
#define R0 PIN_NUM_0
#define R1 PIN_NUM_1
#define R2 PIN_NUM_3
#define R3 PIN_NUM_4
#define C0 PIN_NUM_5
#define C1 PIN_NUM_6
#define C2 PIN_NUM_7
#define C3 PIN_NUM_8

//keypad ports
#define Keypad_PORT GPIOB
//functions
void Keypad_INIT();
char Keypad_GET_CHAR();

#endif /*INC_KEYPAD_H_*/
