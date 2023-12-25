/*************************************************************************/
// Author        : Marina Safwat Barsoum Gerges
// Project       : Student_Information_Management_System_Project
// File          : FIFO.h
// Date          : Dec 22, 2023
// GitHub        : https://github.com/Marina-Safwat
/*************************************************************************/

#ifndef FIFO_H_
#define FIFO_H_

#include <stdio.h>
#include "Platform_Types.h"
#include "Students.h"

#define elementType struct Student

typedef struct Buf{
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

Buffer_Status FIFO_init(FIFO_Buffer_t* Buff,elementType* Buff_arr,uint32_t Length);
Buffer_Status FIFO_add_item(FIFO_Buffer_t*,elementType item);
Buffer_Status FIFO_pop_item(FIFO_Buffer_t*,elementType* item);
Buffer_Status FIFO_Is_Buffer_Full(FIFO_Buffer_t* Buff);
Buffer_Status FIFO_Is_Buffer_NULL(FIFO_Buffer_t* Buff);
Buffer_Status FIFO_Is_Buffer_Empty(FIFO_Buffer_t* Buff);
void FIFO_Print(FIFO_Buffer_t* Buff);

#endif