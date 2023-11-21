#include "Uart.h"

uint8 string[100]="Learn-in-depth:Marina-Safwat";
uint8 const string2[100]=" Hello";

void main(void)
{
	Uart_Sent_String(string);
	//Uart_Sent_String(string2);
}