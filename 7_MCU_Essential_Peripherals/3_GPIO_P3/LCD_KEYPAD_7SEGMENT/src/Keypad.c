/*

 * Keypad.c
 *
 *  Created on: Apr 27, 2024
 *      Author: Marina

 */

#include "Keypad.h"

char Keypad_C[4] = { C0 , C1 , C2 , C3 };
char Keypad_R[4] = { R0 , R1 , R2 , R3 };
char Keypad[4][4] = {
		{'7', '4', '1', '?'},
		{'8', '5', '2', '0'},
		{'9', '6', '3', '='},
		{'/', '*', '-', '+'}
};

void KEYPAD_GPIO_CONFIG(){
	PIN_CONFIG pin_config;

	//make PORTB Row input floating
	pin_config.PIN_NUM = R0;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(Keypad_PORT, &pin_config);

	pin_config.PIN_NUM = R1;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(Keypad_PORT, &pin_config);

	pin_config.PIN_NUM = R2;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(Keypad_PORT, &pin_config);

	pin_config.PIN_NUM = R3;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(Keypad_PORT, &pin_config);

	//make PORTB column output push pull 10 MHZ
	pin_config.PIN_NUM = C0;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(Keypad_PORT, &pin_config);

	pin_config.PIN_NUM = C1;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(Keypad_PORT, &pin_config);

	pin_config.PIN_NUM = C2;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(Keypad_PORT, &pin_config);

	pin_config.PIN_NUM = C3;
	pin_config.PIN_OUT_SPEED = PIN_SPEED_10MHZ;
	pin_config.PIN_MODE = PIN_MODE_OUT_PP;
	MCAL_GPIO_Init(Keypad_PORT, &pin_config);
}

void Keypad_INIT()
{
	KEYPAD_GPIO_CONFIG();

	//set all VCC
	MCAL_GPIO_WRITE_PORT(Keypad_PORT, 0xFFFF);
}

char Keypad_GET_CHAR()
{
	int i,j;
	for(i = 0 ; i < 4 ; i++)
	{
		//set pins of columns on
		MCAL_GPIO_WRITE_PIN(Keypad_PORT, C0, PIN_VALUE_1);
		MCAL_GPIO_WRITE_PIN(Keypad_PORT, C1, PIN_VALUE_1);
		MCAL_GPIO_WRITE_PIN(Keypad_PORT, C2, PIN_VALUE_1);
		MCAL_GPIO_WRITE_PIN(Keypad_PORT, C3, PIN_VALUE_1);

		//set column number i off
		MCAL_GPIO_WRITE_PIN(Keypad_PORT, Keypad_C[i], PIN_VALUE_0);

		//check for the rows
		for(j = 0 ; j < 4 ; j++)
		{
			//check if there is a pressed key in this row
			if(MCAL_GPIO_READ_PIN(Keypad_PORT, Keypad_R[j]) == 0)
			{
				while(MCAL_GPIO_READ_PIN(Keypad_PORT, Keypad_R[j]) == 0);
				return Keypad[i][j];
			}
		}
	}
	return 'A';
}
