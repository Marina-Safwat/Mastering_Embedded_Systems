/*
 * LCD.c
 *
 *  Created on: Apr 27, 2024
 *      Author: Marina
 */

#include "LCD.h"

int count = 0;
PIN_CONFIG pin_config;

void Wait_MS(uint32_t time){
	volatile uint32_t i,j;
	for(i = 0;i < time;i++)
		for(j = 0;j < 255;j++);
}

void READ()
{
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RW, PIN_VALUE_1);
}

void WRITE()
{
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RW, PIN_VALUE_0);
}

void COMMAND()
{
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RS, PIN_VALUE_0);
}

void DATA()
{
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RS, PIN_VALUE_1);
}

void CTRL_INIT()
{
	//make control pins output

	//make PORTA RS pin output push pull
	pin_config.PIN_NUM = RS;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &pin_config);

	//make PORTA RW pin output push pull
	pin_config.PIN_NUM = RW;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &pin_config);

	//make PORTA enable pin output push pull
	pin_config.PIN_NUM = EN;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &pin_config);
}

void LCD_KICK()
{
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, EN, PIN_VALUE_1);
	Wait_MS(50);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, EN, PIN_VALUE_0);
}

void WRITE_COMMAND(unsigned char command)
{
	LCD_IS_Busy();
	WRITE();
	COMMAND();

	//send command
	MCAL_GPIO_WRITE_PORT(LCD_PORT, command);

	//Delay
	//Wait_MS(2);

	LCD_KICK();
}

void LCD_CLR_SCREEN()
{
	WRITE_COMMAND(LCD_CLEAR_SCREEN);
	count = 0;
}

void MAKE_DATA_PIN_INPUT(){
	//make data pins input
	//make PORTA 0 >>> 7 input floating
	pin_config.PIN_NUM = PIN_NUM_0;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_RESET;
	pin_config.PIN_MODE = PIN_MODE_IN_FLO;
	MCAL_GPIO_Init(LCD_PORT, &pin_config);

	pin_config.PIN_NUM = PIN_NUM_1;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_RESET;
	pin_config.PIN_MODE = PIN_MODE_IN_FLO;
	MCAL_GPIO_Init(LCD_PORT, &pin_config);

	pin_config.PIN_NUM = PIN_NUM_2;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_RESET;
	pin_config.PIN_MODE = PIN_MODE_IN_FLO;
	MCAL_GPIO_Init(LCD_PORT, &pin_config);

	pin_config.PIN_NUM = PIN_NUM_3;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_RESET;
	pin_config.PIN_MODE = PIN_MODE_IN_FLO;
	MCAL_GPIO_Init(LCD_PORT, &pin_config);

	pin_config.PIN_NUM = PIN_NUM_4;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_RESET;
	pin_config.PIN_MODE = PIN_MODE_IN_FLO;
	MCAL_GPIO_Init(LCD_PORT, &pin_config);

	pin_config.PIN_NUM = PIN_NUM_5;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_RESET;
	pin_config.PIN_MODE = PIN_MODE_IN_FLO;
	MCAL_GPIO_Init(LCD_PORT, &pin_config);

	pin_config.PIN_NUM = PIN_NUM_6;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_RESET;
	pin_config.PIN_MODE = PIN_MODE_IN_FLO;
	MCAL_GPIO_Init(LCD_PORT, &pin_config);

	pin_config.PIN_NUM = PIN_NUM_7;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_RESET;
	pin_config.PIN_MODE = PIN_MODE_IN_FLO;
	MCAL_GPIO_Init(LCD_PORT, &pin_config);
}

void MAKE_DATA_PIN_OUTPUT(){
	//make data pins output
	//make PORTA 0 >>> 7 output push pull 10 MHZ
	pin_config.PIN_NUM = PIN_NUM_0;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(LCD_PORT, &pin_config);

	pin_config.PIN_NUM = PIN_NUM_1;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(LCD_PORT, &pin_config);

	pin_config.PIN_NUM = PIN_NUM_2;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(LCD_PORT, &pin_config);

	pin_config.PIN_NUM = PIN_NUM_3;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(LCD_PORT, &pin_config);

	pin_config.PIN_NUM = PIN_NUM_4;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(LCD_PORT, &pin_config);

	pin_config.PIN_NUM = PIN_NUM_5;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(LCD_PORT, &pin_config);

	pin_config.PIN_NUM = PIN_NUM_6;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(LCD_PORT, &pin_config);

	pin_config.PIN_NUM = PIN_NUM_7;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(LCD_PORT, &pin_config);
}

void LCD_IS_Busy()
{
	//make data pins input
	//make PORTA 0 >>> 7 input floating
	MAKE_DATA_PIN_INPUT();

	//read command mode
	READ();
	COMMAND();

	//LCD kick
	LCD_KICK();

	//if LCD busy wait
	if(MCAL_GPIO_READ_PIN(LCD_PORT, PIN_NUM_7))
	{
		Wait_MS(20);
	}
	//make data pins output
	MAKE_DATA_PIN_OUTPUT();

	//turn back to write
	WRITE();
}

void LCD_INIT()
{
	Wait_MS(20);
	CTRL_INIT();

	LCD_IS_Busy();
	Wait_MS(15);

	LCD_CLR_SCREEN();
	WRITE_COMMAND(LCD_8BIT_2LINES);
	WRITE_COMMAND(LCD_ENTRY_MODE);
	WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_WRITE_CHAR(unsigned char c)
{
	//check if it is busy
	LCD_IS_Busy();

	//put data
	MCAL_GPIO_WRITE_PORT(LCD_PORT, c);

	//write data
	WRITE();
	DATA();

	//Wait_MS(2);
	LCD_KICK();
	count++;
	if(count == 16)
	{
		LCD_GOTO_XY(1,0);
	}
	else if(count ==32)
	{
		LCD_CLR_SCREEN();
		LCD_GOTO_XY(0,0);
		count = 0;
	}
}

void LCD_WRITE_STR(char * s)
{
	while(*s > 0)
	{
		LCD_WRITE_CHAR(*s);
		s++;
	}
}

void LCD_GOTO_XY(unsigned char line,unsigned char position)
{
	if(line == 0)
	{
		if(position >= 0 && position < 16)
		{
			WRITE_COMMAND(0x80 + position);
		}
	}
	else if(line == 1)
	{
		if(position >= 0 && position < 16)
		{
			WRITE_COMMAND(0xC0 + position);
		}
	}
}

void LCD_WRITE_NUM(int num)
{
	char str[7];
	//sprintf(str,"%d",num);
	LCD_WRITE_STR(str);
}
