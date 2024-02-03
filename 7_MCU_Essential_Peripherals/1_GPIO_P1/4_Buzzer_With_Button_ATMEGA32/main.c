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
    SETBIT(DDRD,4);
	CLRBIT(DDRD,0);
	CLRBIT(PORTD,0);
	
	//create counters
	volatile unsigned char SP = 0;
	
    while (1) 
    {
		if(GETBIT(PIND,0) == 1&& SP == 0)
		{
			SETBIT(PORTD,4);
			_delay_ms(500);
			CLRBIT(PORTD,4);
			SP = 1;
		}
		if(GETBIT(PIND,0) == 0)
		{
			SP = 0;
		}
		_delay_ms(20);
    }
}

