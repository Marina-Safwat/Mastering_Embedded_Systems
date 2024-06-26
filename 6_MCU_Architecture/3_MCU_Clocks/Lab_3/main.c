/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x40010800

#define RCC_APB2ENR *((volatile uint32_t *)(RCC_BASE + 0x18))
#define GPIOA_CRH *((volatile uint32_t *)(GPIOA_BASE + 0x04))
#define GPIOA_ODR *((volatile uint32_t *)(GPIOA_BASE + 0x0C))

#define RCC_CFGR *((volatile uint32_t *)(RCC_BASE + 0x04))
#define RCC_CR *((volatile uint32_t *)(RCC_BASE + 0x00))

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

int main(void)
{
	//use PLLMUL to multiple by 8
	CLRBIT(RCC_CFGR,18);
	SETBIT(RCC_CFGR,19);
	SETBIT(RCC_CFGR,20);
	CLRBIT(RCC_CFGR,21);

	//choose PLL as system clock
	CLRBIT(RCC_CFGR,0);
	SETBIT(RCC_CFGR,1);

	//enable PLL
	SETBIT(RCC_CR,24);

	//make APB1 work with 4HZ
	SETBIT(RCC_CFGR,10);

	//make APB2 work with 2HZ
	SETBIT(RCC_CFGR,11);
	CLRBIT(RCC_CFGR,12);
	SETBIT(RCC_CFGR,13);

	//enable clock for GPIO port A
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

