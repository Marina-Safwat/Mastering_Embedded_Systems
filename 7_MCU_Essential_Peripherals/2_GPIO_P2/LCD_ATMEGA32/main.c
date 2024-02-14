/*
 * LCD_Driver.c
 *
 * Created: 2/14/2024 3:02:55 PM
 * Author: Marina
 */ 
#include "LCD.h"

int main(void)
{
    LCD_INIT();
    while (1) 
    {
		LCD_WRITE_STR("Marina Safwat is an Embedded Engineer number ");
		_delay_ms(1000);
		LCD_CLR_SCREEN();
		LCD_WRITE_NUM(1);
		_delay_ms(1000);
		LCD_CLR_SCREEN();
		_delay_ms(1000);
    }
}

