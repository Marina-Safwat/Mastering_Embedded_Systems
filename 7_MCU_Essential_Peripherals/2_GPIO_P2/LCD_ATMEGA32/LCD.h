/*
 * LCD.h
 *
 * Created: 2/14/2024 6:37:32 PM
 *  Author: Marina
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000UL
#include <util/delay.h>
#include "GPIO.h"
#include "BitMasks.h"

//LCD Modes
#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

//data pins
#define LCD_PORT PORTA
#define LCD_PORT_DDR DDRA
#define LCD_PORT_PIN PINA

//control pins
#define LCD_CTRL_PORT PORTB
#define LCD_CTRL_PORT_DDR DDRB
#define LCD_CTRL_PORT_PIN PINB

#define RS 0
#define RW 1
#define EN 2

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

#endif /* LCD_H_ */