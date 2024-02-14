/*
 * LCD.c
 *
 * Created: 2/14/2024 3:05:37 PM
 *  Author: Marina
 */ 
#include "LCD.h"

int count = 0;

void READ()
{
	SETBIT(LCD_CTRL_PORT,RW);
}

void WRITE()
{
	CLRBIT(LCD_CTRL_PORT,RW);
}

void COMMAND()
{
	CLRBIT(LCD_CTRL_PORT,RS);
}

void DATA()
{
	SETBIT(LCD_CTRL_PORT,RS);
}

void CTRL_INIT()
{
	//make control pins output
	SETBIT(LCD_CTRL_PORT_DDR,RW);
	SETBIT(LCD_CTRL_PORT_DDR,RS);
	SETBIT(LCD_CTRL_PORT_DDR,EN);
}

void LCD_KICK()
{
	SETBIT(LCD_CTRL_PORT,EN);
	_delay_ms(50);
	CLRBIT(LCD_CTRL_PORT,EN);
}

void WRITE_COMMAND(unsigned char command)
{
	LCD_IS_Busy();
	WRITE();
	COMMAND();
	
	#ifdef EIGHT_BIT_MODE
	//send command
	LCD_PORT = command;
#endif
	#ifdef FOUR_BIT_MODE
	SSD_HIGH_HIGH_NIBBLE(LCD_PORT,command);
	LCD_KICK();
	SSD_LOW_HIGH_NIBBLE(LCD_PORT,command);
#endif
	
	LCD_KICK();
}

void LCD_CLR_SCREEN()
{
	WRITE_COMMAND(LCD_CLEAR_SCREEN);
	count = 0;
}

void LCD_IS_Busy()
{
	//for 8-bit mode LCD
	#ifdef EIGHT_BIT_MODE
	
	//make data pins input
	LCD_PORT_DDR = 0x00;
#endif

	//for 4-bit mode LCD
	#ifdef FOUR_BIT_MODE

	//make data pins input
	CLR_HIGH_NIBBLE(LCD_PORT_DDR);
#endif

	//read command mode
	READ();
	COMMAND();
	
	//LCD kick
	LCD_KICK();

	//if LCD busy wait
	if(GETBIT(LCD_PORT_PIN,7))
	{
		_delay_ms(20);
	}
	
	//for 8-bit mode LCD
	#ifdef EIGHT_BIT_MODE
	
	//make data pins output
	LCD_PORT_DDR = 0xFF;
	#endif

	//for 4-bit mode LCD
	#ifdef FOUR_BIT_MODE

	//make data pins output
	SET_HIGH_NIBBLE(LCD_PORT_DDR);
	#endif
	
	//turn back to write 
	WRITE();
}

void LCD_INIT()
{
	_delay_ms(20);
	CTRL_INIT();
	
	LCD_IS_Busy();
	_delay_ms(15);
	
	LCD_CLR_SCREEN();
	
	//for 8-bit mode LCD
	#ifdef EIGHT_BIT_MODE
	WRITE_COMMAND(LCD_8BIT_2LINES);
#endif

	//for 4-bit mode LCD
	#ifdef FOUR_BIT_MODE
	WRITE_COMMAND(0x02);
	WRITE_COMMAND(LCD_4BIT_2LINES);
#endif

	WRITE_COMMAND(LCD_ENTRY_MODE);
	WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_WRITE_CHAR(unsigned char c)
{
	//check if it is busy
	LCD_IS_Busy();
	
	//write data
	WRITE();
	DATA();
	
	//put data
	//for 8-bit mode
	#ifdef EIGHT_BIT_MODE
	LCD_PORT = c;
#endif
	//for 4-bit mode
	#ifdef FOUR_BIT_MODE
	SSD_HIGH_HIGH_NIBBLE(LCD_PORT,c);
	LCD_KICK();
	SSD_LOW_HIGH_NIBBLE(LCD_PORT,c);
#endif

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
	sprintf(str,"%d",num);
	LCD_WRITE_STR(str);
}