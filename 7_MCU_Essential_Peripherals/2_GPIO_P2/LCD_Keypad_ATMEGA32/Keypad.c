/*
 * Keypad.c
 *
 * Created: 2/14/2024 7:00:16 PM
 *  Author: Marina
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

void Keypad_INIT()
{
	//set pins of rows input
	CLR_LOW_NIBBLE(Keypad_DDR);
	
	//set pins of columns output
	SET_HIGH_NIBBLE(Keypad_DDR);
	
	//set all VCC
	Keypad_PORT = 0xFF;
}

char Keypad_GET_CHAR()
{
	int i,j;
	for(i = 0 ; i < 4 ; i++)
	{
		//set pins of columns on
		SET_HIGH_NIBBLE(Keypad_PORT);
		
		//set column number i off
		CLRBIT(Keypad_PORT,Keypad_C[i]);
		
		//check for the rows
		for(j = 0 ; j < 4 ; j++)
		{
			//check if there is a pressed key in this row
			if(!(GETBIT(Keypad_PIN,Keypad_R[j])))
			{
				while(!(GETBIT(Keypad_PIN,Keypad_R[j])));
				return Keypad[i][j];
			}
		}
	}
	return 'A';
}