// by Marina Safwat
// 11/12/2023

#include "LIFO.h"

Buffer_Status LIFO_add_item(LIFO_Buffer_t* Buff,elementType item)
{
	// checking if the buffer is exist
	if(LIFO_Is_Buffer_NULL(Buff) == LIFO_NULL)
		return LIFO_NULL;
	
	//check if there is space for adding element
	if(LIFO_Is_Buffer_Full(Buff) == LIFO_Full)
		return LIFO_Full;
	
	//adding the item and increment count
	*(Buff->head) = item;
	Buff->head++; // make the head point to the next space
	Buff->count++;
	
	printf("------------LIFO_ADD_%d----------\n",item);
	
	return LIFO_No_Error;
}

Buffer_Status LIFO_pop_item(LIFO_Buffer_t* Buff,elementType* item)
{
	// checking if the buffer is exist
	if(LIFO_Is_Buffer_NULL(Buff) == LIFO_NULL)
		return LIFO_NULL;
	
	//check if there is space for adding element
	if(LIFO_Is_Buffer_Empty(Buff) == LIFO_Empty)
		return LIFO_Empty;
	
	//get the item
	Buff->head--;
	*item = *(Buff->head);
	Buff->count--;
	
	printf("------------LIFO_POP_%d----------\n",*item);
	
	return LIFO_No_Error; 
}

Buffer_Status LIFO_Is_Buffer_Full(LIFO_Buffer_t* Buff)
{
	if(Buff->count == Buff->length)
		return LIFO_Full;
	else
		return LIFO_NOT_Full;
}

Buffer_Status LIFO_Is_Buffer_NULL(LIFO_Buffer_t* Buff)
{
	if(!Buff->base || !Buff->head || !Buff)
		return LIFO_NULL;
	else
		return LIFO_NOT_NULL;
}

Buffer_Status LIFO_Is_Buffer_Empty(LIFO_Buffer_t* Buff)
{
	if(Buff->count == 0 || Buff->base == Buff->head)
		return LIFO_Empty;
	else
		return LIFO_NOT_Empty;
}

Buffer_Status LIFO_init(LIFO_Buffer_t* Buff,elementType* Buff_arr,uint32_t Length)
{
	// check if the buffer array is exist
	if(Buff_arr == NULL)
		return LIFO_NULL;
	
	//setup Buff information
	Buff->base = Buff_arr;
	Buff->head = Buff_arr;
	Buff->length = Length;
	Buff->count = 0;
	
	printf("------------LIFO_INIT----------\n");
	
	return LIFO_No_Error; 
}