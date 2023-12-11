// main to apply on LIFO Buffer
// by Marina Safwat
// 11/12/2023

#include "LIFO.h"
#include <stdlib.h>

#define Buffer_Length 5

elementType buffer1[Buffer_Length]; // take 20 bytes

int main()
{
	elementType temp , i;
	LIFO_Buffer_t uart_lifo,I2C_lifo;
	//static allocation
	LIFO_init(&uart_lifo,buffer1,Buffer_Length);
	//dynamic allocation
	elementType* buffer2 = (elementType*) malloc(Buffer_Length*sizeof(elementType)); // take 20 bytes
	LIFO_init(&I2C_lifo,buffer2,Buffer_Length);
	for(i = 0; i<5 ; i++)
		LIFO_add_item(&uart_lifo,i);
	for(i = 0; i<5 ; i++)
		LIFO_pop_item(&uart_lifo,&temp);
}