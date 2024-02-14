/*
 * LCD_Keypad_Driver.c
 *
 * Created: 2/14/2024 3:02:55 PM
 * Author: Marina
 */ 

#include "\study\Embedded\KS_Diploma\Material\7_MCU_Essential_Peripherals\2_AFIO\Labs\LCD_Keypad_Driver\LCD_Keypad_Driver\LCD_Driver\LCD.h"
#include "\study\Embedded\KS_Diploma\Material\7_MCU_Essential_Peripherals\2_AFIO\Labs\LCD_Keypad_Driver\LCD_Keypad_Driver\Keypad_Driver\Keypad.h"

int main(void)
{
	volatile char Key_Pressed ;
    LCD_INIT();
	Keypad_INIT();
	
    while (1) 
    {
		Key_Pressed = Keypad_GET_CHAR();
		if(Key_Pressed != 'A')
		{
			if(Key_Pressed == '?')
			{
				LCD_CLR_SCREEN();
			}
			else
			{
				LCD_WRITE_CHAR(Key_Pressed);
			}
		}
    }
}

