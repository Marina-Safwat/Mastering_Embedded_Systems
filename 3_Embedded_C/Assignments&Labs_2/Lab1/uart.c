#include "Uart.h"

#define UART0DR *((vuint32* const)((uint32 *)0x101f1000))

void Uart_Sent_String(uint8 *P_String)
{
	while(*P_String!='\0')
	{
		UART0DR = (uint32)(*P_String);
		P_String++;
	}
}