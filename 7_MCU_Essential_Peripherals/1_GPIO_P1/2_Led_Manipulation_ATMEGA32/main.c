/*
 * LedManipulation.c
 *
 * Created: 2/1/2024 9:24:38 AM
 * Author: Marina
 */ 

#define F_CPU 8000000UL

#include "MemoryMap.h"
#include "BitMasks.h"
#include <util/delay.h>

int main(void)
{
	//make all pins in port A output
    DDRA = 0xff;
	
	//create counters
	volatile unsigned char i = 0;
	volatile unsigned char flag = 0;
	
    while (1) 
    {
		if(flag)
		{
			CLRBIT(PORTA,i);
			i--;
		}
		else
		{
			SETBIT(PORTA,i);
			i++;
		}
		if(i == 8)
		{
			flag = 1;
			i=7;
		}
		if(i == 255)
		{
			flag = 0;
			i=0;
		}
		_delay_ms(200);
    }
}

