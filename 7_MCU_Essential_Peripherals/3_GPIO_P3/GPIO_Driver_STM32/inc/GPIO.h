/*
 * GPIO.h
 *
 *  Created on: Apr 22, 2024
 *      Author: Marina
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

//-----------------------------
//Includes
//-----------------------------

#include "STM32F103x6.h"
//================================================

//-----------------------------
//Structures
//-----------------------------

//configuration structure
typedef struct{
	//specify number of pin to be configured
	uint16_t PIN_NUM;	//@ref PIN_NUM_define
	//specify the operation mode of selected pin
	uint8_t PIN_MODE;	//@ref PIN_MODE_define
	//specify the speed if it is output
	uint8_t PIN_OUT_SPEED;	//@ref PIN_SPEED_define

}PIN_CONFIG;
//================================================

//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref PIN_NUM_define
#define PIN_NUM_0 	0
#define PIN_NUM_1 	1
#define PIN_NUM_2 	2
#define PIN_NUM_3 	3
#define PIN_NUM_4 	4
#define PIN_NUM_5 	5
#define PIN_NUM_6 	6
#define PIN_NUM_7 	7
#define PIN_NUM_8 	8
#define PIN_NUM_9 	9
#define PIN_NUM_10 	10
#define PIN_NUM_11 	11
#define PIN_NUM_12 	12
#define PIN_NUM_13 	13
#define PIN_NUM_14 	14
#define PIN_NUM_15 	15

//@ref PIN_MODE_define
/*
0: Analog mode
1: Floating input (reset state)
2: Input with pull-up
3: Input with pull-down
4: Alternate function input
5: General purpose output push-pull
6: General purpose output Open-drain
7: Alternate function output Push-pull
8: Alternate function output Open-drain

*/
#define PIN_MODE_ANALOG	0	//Analog mode
#define PIN_MODE_IN_FLO 1	//Floating input
#define PIN_MODE_IN_PU 	2	//Input with pull-up
#define PIN_MODE_IN_PD 	3	//Input with pull-down
#define PIN_MODE_IN_ALT 4	//Alternate function input
#define PIN_MODE_OUT_PP 5	//output push-pull
#define PIN_MODE_OUT_OD 6	//output Open-drain
#define PIN_MODE_ALT_PP 7	//Alternate function output Push-pull
#define PIN_MODE_ALT_OD 8	//Alternate function output Open-drain

//@ref PIN_SPEED_define
/*
0: Input mode (reset state)
1: Output mode, max speed 10 MHz.
2: Output mode, max speed 2 MHz.
3: Output mode, max speed 50 MHz.
*/
#define PIN_SPEED_RESET 0	//Input mode
#define PIN_SPEED_10MHZ 1	//Output mode, max speed 10 MHz.
#define PIN_SPEED_2MHZ 	2	//Output mode, max speed 2 MHz.
#define PIN_SPEED_50MHZ 3	//Output mode, max speed 50 MHz.

//@ref PIN_VALUE
/*
0: pin on
1: pin off
 */
#define PIN_VALUE_0 0
#define PIN_VALUE_1 1

//@ref STATUS_define
/*
0: Failed
1: Done
 */
#define STATUS_OK 		1
#define STATUS_ERROR 	0
//================================================

//-----------------------------
//APIs Supported by "MCAL GPIO DRIVER"
//-----------------------------

void MCAL_GPIO_Init(GPIO_T * GPIOx,PIN_CONFIG * PIN);
void MCAL_GPIO_DEINIT_PORT(GPIO_T * GPIOx);

void MCAL_GPIO_RESET_PORT(GPIO_T * GPIOx);
void MCAL_GPIO_RESET_BIT(GPIO_T * GPIOx,uint16_t PIN_NUM);

uint8_t MCAL_GPIO_READ_PIN(GPIO_T * GPIOx,uint16_t PIN_NUM);
uint16_t MCAL_GPIO_READ_PORT(GPIO_T * GPIOx);

void MCAL_GPIO_WRITE_PIN(GPIO_T * GPIOx,uint16_t PIN_NUM,uint8_t VALUE);
void MCAL_GPIO_WRITE_PORT(GPIO_T * GPIOx,uint16_t VALUE);

void MCAL_GPIO_TOGGLE_PIN(GPIO_T * GPIOx,uint32_t PIN_NUM);

uint8_t MCAL_GPIO_LOCK_PIN(GPIO_T * GPIOx,uint32_t PIN_NUM);
#endif /* INC_GPIO_H_ */
