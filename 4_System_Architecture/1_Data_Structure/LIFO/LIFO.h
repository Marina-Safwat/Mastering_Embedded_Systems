// by Marina Safwat
// 11/12/2023

#ifndef _LIFO_H
#define _LIFO_H

#include <stdint.h>
#include <stdio.h>

#define elementType uint32_t

typedef struct {
	uint32_t length;
	uint32_t count;
	elementType* base;
	elementType* head;
}LIFO_Buffer_t;

typedef enum{
	LIFO_No_Error,
	LIFO_Full,
	LIFO_NOT_Full,
	LIFO_Empty,
	LIFO_NOT_Empty,
	LIFO_NULL,
	LIFO_NOT_NULL
}Buffer_Status;

Buffer_Status LIFO_add_item(LIFO_Buffer_t*,elementType item);
Buffer_Status LIFO_pop_item(LIFO_Buffer_t*,elementType* item);
Buffer_Status LIFO_Is_Buffer_Full(LIFO_Buffer_t* Buff);
Buffer_Status LIFO_Is_Buffer_NULL(LIFO_Buffer_t* Buff);
Buffer_Status LIFO_Is_Buffer_Empty(LIFO_Buffer_t* Buff);
Buffer_Status LIFO_init(LIFO_Buffer_t* Buff,elementType* Buff_arr,uint32_t Length);

#endif