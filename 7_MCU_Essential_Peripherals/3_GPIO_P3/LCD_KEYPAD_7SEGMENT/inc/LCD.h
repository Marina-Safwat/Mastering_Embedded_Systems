/*
 * LCD.h
 *
 *  Created on: Apr 27, 2024
 *      Author: Marina
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_


#define F_CPU 1000000UL
#include "BitMasks.h"
#include "GPIO.h"
#include "STM32F103x6.h"

//LCD Modes
#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

//data pins
#define LCD_PORT GPIOA

//control pins
#define LCD_CTRL_PORT GPIOA

#define RS PIN_NUM_8
#define RW PIN_NUM_9
#define EN PIN_NUM_10

//LCD commands
#define LCD_CLEAR_SCREEN 0x01
#define LCD_8BIT_2LINES 0x38
#define LCD_4BIT_2LINES 0x28
#define LCD_ENTRY_MODE 0x06
#define LCD_BEGIN_AT_FIRST_ROW 0x80
#define LCD_DISP_ON_CURSOR_BLINK 0x0F

//functions
void LCD_INIT();
void LCD_IS_Busy();
void WRITE_COMMAND(unsigned char command);
void LCD_CLR_SCREEN();
void LCD_KICK();
void LCD_WRITE_CHAR(unsigned char c);
void LCD_GOTO_XY(unsigned char line ,unsigned char position);
void LCD_WRITE_STR(char * s);
void LCD_WRITE_NUM(int num);

void Wait_MS(uint32_t time);

#endif /* INC_LCD_H_ */
