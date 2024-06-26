/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdlib.h>

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x40010800

#define RCC_APB2ENR *((volatile uint32_t *)(RCC_BASE + 0x18))
#define GPIOA_CRH *((volatile uint32_t *)(GPIOA_BASE + 0x04))
#define GPIOA_ODR *((volatile uint32_t *)(GPIOA_BASE + 0x0C))

#define SETBIT(reg,bit) reg|=(1<<bit)
#define CLRBIT(reg,bit) reg&=~(1<<bit)

typedef union{
	volatile uint32_t all_fields;
	struct{
		volatile uint32_t reserved:13;
		volatile uint32_t pin_13:1;
	}pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);

void* _sbrk(int incr);

int main(void)
{
	int* p = (int *)malloc(4);
	free(p);
	SETBIT(RCC_APB2ENR,2);
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
    /* Loop forever */
	while(1)
	{
		R_ODR->pin.pin_13 = 1;
		for(int i =0;i<5000;i++);
		R_ODR->pin.pin_13 = 0;
		for(int i =0;i<5000;i++);
	}
}

void* _sbrk(int incr)
{
	static unsigned char* heap_ptr = NULL;
	unsigned char* pre_heap_ptr = NULL;
	extern unsigned int _E_bss; //symbol
	extern unsigned int _heap_End; //symbol
	
	//first time initialized
	if(heap_ptr == NULL)
		heap_ptr = (unsigned char*)&_E_bss;
	
	pre_heap_ptr = heap_ptr;
	
	//protect stack
	if((heap_ptr + incr)>((unsigned char*)&_heap_End))
		return (void*) NULL;
	
	//booking incr size
	heap_ptr += incr;
	
	return (void*) pre_heap_ptr;
}