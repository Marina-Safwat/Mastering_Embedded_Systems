/*
 * GccApplication1.c
 *
 * Created: 1/25/2024 2:07:50 AM
 * Author: Marina
 */ 

#define F_CPU 8000000ul
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

//Bit manipulation
#define SETBIT(REG,BIT) REG|=(1<<BIT)
#define CLRBIT(REG,BIT) REG&=~(1<<BIT)
#define TGLBIT(REG,BIT) REG^=(1<<BIT)

void EXTI()
{
	//enable interrupts
	SETBIT(GICR,7); //INT1
	SETBIT(GICR,6); //INT0
	SETBIT(GICR,5); //INT2
	
	//make INT0 generated in any logical change
	SETBIT(MCUCR,0);
	CLRBIT(MCUCR,1);
	
	//make INT1 generated in a rising edge
	SETBIT(MCUCR,2);
	SETBIT(MCUCR,3);
	
	//make INT2 generated in falling edge
	CLRBIT(MCUCSR,6);
	
	//Global interrupt enable
	SETBIT(SREG,7);
}

void GPIO_INIT()
{
	SETBIT(DDRD,7);
	SETBIT(DDRD,6);
	SETBIT(DDRD,5);
}

int main(void)
{
	EXTI();
	GPIO_INIT();
	
    /* Replace with your application code */
    while (1)
	{
		CLRBIT(PORTD,5);
		CLRBIT(PORTD,6);
		CLRBIT(PORTD,7);
		_delay_ms(500);
	}
}

ISR(INT0_vect)
{
	SETBIT(PORTD,5);
	_delay_ms(500);
	//CLRBIT(PORTD,5);
	//_delay_ms(1000);
}

ISR(INT1_vect)
{
	SETBIT(PORTD,6);
	_delay_ms(500);
	//CLRBIT(PORTD,6);
	//_delay_ms(1000);
}

ISR(INT2_vect)
{
	SETBIT(PORTD,7);
	_delay_ms(500);
	//CLRBIT(PORTD,7);
	//_delay_ms(1000);
}

