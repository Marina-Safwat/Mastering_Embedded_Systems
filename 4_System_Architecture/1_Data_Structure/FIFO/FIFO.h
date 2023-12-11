// by Marina Safwat
// 11/12/2023

#ifndef _FIFO_H_
#define _FIFO_H_

#include <stdint.h>
#include <stdio.h>

#define elementType uint32_t

typedef struct {
	uint32_t length;
	uint32_t count;
	elementType* base;
	elementType* head;
	elementType* tail;
}FIFO_Buffer_t;

typedef enum{
	FIFO_No_Error,
	FIFO_Full,
	FIFO_NOT_Full,
	FIFO_Empty,
	FIFO_NOT_Empty,
	FIFO_NULL,
	FIFO_NOT_NULL
}Buffer_Status;

Buffer_Status FIFO_add_item(FIFO_Buffer_t*,elementType item);
Buffer_Status FIFO_pop_item(FIFO_Buffer_t*,elementType* item);
Buffer_Status FIFO_Is_Buffer_Full(FIFO_Buffer_t* Buff);
Buffer_Status FIFO_Is_Buffer_NULL(FIFO_Buffer_t* Buff);
Buffer_Status FIFO_Is_Buffer_Empty(FIFO_Buffer_t* Buff);
Buffer_Status FIFO_init(FIFO_Buffer_t* Buff,elementType* Buff_arr,uint32_t Length);
void FIFO_Print(FIFO_Buffer_t* Buff);

#endif