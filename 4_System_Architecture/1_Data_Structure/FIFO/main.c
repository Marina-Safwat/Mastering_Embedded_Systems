// main to apply on LIFO Buffer
// by Marina Safwat
// 11/12/2023

#include "FIFO.h"
#include <stdlib.h>

#define Buffer_Length 5

elementType buffer1[Buffer_Length]; // take 20 bytes

int main()
{
	elementType temp , i;
	FIFO_Buffer_t uart_fifo;
	//static allocation
	FIFO_init(&uart_fifo,buffer1,Buffer_Length);
	
	for(i = 0; i<7 ; i++)
	{
		if(FIFO_add_item(&uart_fifo,i) == FIFO_No_Error)
			printf("enqueue Done\n");
		else
			printf("enqueue failed\n");
	}
	
	FIFO_Print(&uart_fifo);
	FIFO_pop_item(&uart_fifo,&temp);
	printf("Value dequeued is %d\n",temp);
	FIFO_pop_item(&uart_fifo,&temp);
	printf("Value dequeued is %d\n",temp);
	for(i = 0; i<2 ; i++)
	{
		if(FIFO_add_item(&uart_fifo,i) == FIFO_No_Error)
			printf("enqueue Done\n");
		else
			printf("enqueue failed\n");
	}
	FIFO_Print(&uart_fifo);
}