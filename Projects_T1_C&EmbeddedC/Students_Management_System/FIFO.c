/*************************************************************************/
// Author        : Marina Safwat Barsoum Gerges
// Project       : Student_Information_Management_System_Project
// File          : FIFO.c
// Date          : Dec 22, 2023
// GitHub        : https://github.com/Marina-Safwat
/*************************************************************************/

#include "FIFO.h"

Buffer_Status FIFO_add_item(FIFO_Buffer_t* Buff,elementType item)
{
	// checking if the buffer is exist
	if(FIFO_Is_Buffer_NULL(Buff) == FIFO_NULL)
		return FIFO_NULL;
	
	//check if there is space for adding element
	if(FIFO_Is_Buffer_Full(Buff) == FIFO_Full)
		return FIFO_Full;
	
	//adding the item and increment count
	*(Buff->head) = item;
	Buff->count++;
	if(Buff->head == (Buff->base + (Buff->length * sizeof(elementType))))
		Buff->head = Buff->base;
	else
		Buff->head++; // make the head point to the next space
	
	printf("------------FIFO_Enqueue_Item----------\n");
	
	return FIFO_No_Error;
}

Buffer_Status FIFO_pop_item(FIFO_Buffer_t* Buff,elementType* item)
{
	// checking if the buffer is exist
	if(FIFO_Is_Buffer_NULL(Buff) == FIFO_NULL)
		return FIFO_NULL;
	
	//check if there is space for adding element
	if(FIFO_Is_Buffer_Empty(Buff) == FIFO_Empty)
		return FIFO_Empty;
	
	//get the item
	Buff->count--;
	*item = *(Buff->tail);
	if(Buff->tail == (Buff->base + (Buff->length * sizeof(elementType))))
		Buff->tail = Buff->base;
	else
		Buff->tail++;
	
	printf("------------FIFO_Dequeue_Item----------\n");
	
	return FIFO_No_Error; 
}

Buffer_Status FIFO_Is_Buffer_Full(FIFO_Buffer_t* Buff)
{
	//check if the Buffer exist
	if(FIFO_Is_Buffer_NULL(Buff) == FIFO_NULL)
		return FIFO_NULL;
	
	if(Buff->count == Buff->length)
		return FIFO_Full;
	else
		return FIFO_NOT_Full;
}

Buffer_Status FIFO_Is_Buffer_NULL(FIFO_Buffer_t* Buff)
{
	if(!Buff->base || !Buff->head || !Buff || !Buff->tail)
		return FIFO_NULL;
	else
		return FIFO_NOT_NULL;
}

Buffer_Status FIFO_Is_Buffer_Empty(FIFO_Buffer_t* Buff)
{
	if(Buff->count == 0)
		return FIFO_Empty;
	else
		return FIFO_NOT_Empty;
}

Buffer_Status FIFO_init(FIFO_Buffer_t* Buff,elementType* Buff_arr,uint32_t Length)
{
	// check if the buffer array is exist
	if(Buff_arr == NULL)
		return FIFO_NULL;
	
	//setup Buff information
	Buff->base = Buff_arr;
	Buff->head = Buff_arr;
	Buff->tail = Buff_arr;
	Buff->length = Length;
	Buff->count = 0;
	
	printf("------------FIFO_INIT_Done----------\n");
	
	return FIFO_No_Error; 
}

void FIFO_Print(FIFO_Buffer_t* Buff)
{
	//check if the Buffer exist
	if(FIFO_Is_Buffer_NULL(Buff) == FIFO_NULL)
		printf("------------FIFO_NULL----------\n");
	
	//check if there is elements to print
	if(FIFO_Is_Buffer_Empty(Buff) == FIFO_Empty)
	{
		printf("FIFO is empty\n");
	}
	
	printf("------------FIFO_Print----------\n");
	elementType* temp = Buff->tail;
	for(int i = 0;i < Buff->count;i++)
	{
		printf("   %d   \n",*temp);
		if(temp == (Buff->base + (Buff->length * sizeof(elementType))))
			temp = Buff->base;
		else
			temp++;
	}
	printf("---------------------------------\n");
}