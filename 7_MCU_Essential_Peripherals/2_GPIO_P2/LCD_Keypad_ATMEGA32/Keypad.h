/*
 * Keypad.h
 *
 * Created: 2/14/2024 7:01:17 PM
 *  Author: Marina
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "/study/Embedded/KS_Diploma/Material/7_MCU_Essential_Peripherals/2_AFIO/Labs/LCD_Keypad_Driver/LCD_Keypad_Driver/GPIO_Driver/GPIO.h"
#include "/study/Embedded/KS_Diploma/Material/7_MCU_Essential_Peripherals/2_AFIO/Labs/LCD_Keypad_Driver/LCD_Keypad_Driver/BitMasks.h"

//keypad pins
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

//keypad ports
#define Keypad_PORT PORTD
#define Keypad_PIN PIND
#define Keypad_DDR DDRD

//functions
void Keypad_INIT();
char Keypad_GET_CHAR();

#endif /* KEYPAD_H_ */