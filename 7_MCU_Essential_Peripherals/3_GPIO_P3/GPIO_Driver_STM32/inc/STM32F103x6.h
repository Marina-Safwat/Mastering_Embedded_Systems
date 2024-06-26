/*
 * STM32F103x6.h
 *
 *  Created on: Apr 22, 2024
 *      Author: Marina
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------

#include "stdlib.h"
#include <stdint.h>
#include "BitMasks.h"
//================================================

//-----------------------------
//Base addresses for Memories
//-----------------------------

#define FLASH_MEMORY_BASE 			0x08000000UL
#define SYSTEM_MEMORY_BASE 			0x1FFFF800UL
#define SRAM_MEMORY_BASE 			0x20000000UL
#define Peripherals_BASE 			0x1FFFF800UL
#define Internal_Peripheral_CM_BASE 0xE0000000UL
//================================================

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------

//RCC
#define RCC_BASE 0x40021000UL
//================================================

//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------

//GPIO
//in LQFP48 Package
//A,B full included
//C,D partial included
//E not included
#define GPIOA_BASE 	0x40010800UL
#define GPIOB_BASE 	0x40010C00UL
#define GPIOC_BASE 	0x40011000UL
#define GPIOD_BASE 	0x40011400UL
#define GPIOE_BASE 	0x40011800UL

//EXTI
#define EXTI_BASE 	0x40010400UL

//AFIO
#define AFIO_BASE 	0x40010000UL
//================================================

//-----------------------------
//Peripheral register
//-----------------------------

//RCC
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;
}RCC_T;

//GPIO
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_T;

//AFIO
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	uint32_t RESERVED_0;
	volatile uint32_t MAPR2;
}AFIO_T;

//EXTI
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_T;
//================================================

//-----------------------------
//Peripheral Instants
//-----------------------------

//RCC
#define RCC 	((RCC_T *)RCC_BASE)

//GPIO
#define GPIOA 	((GPIO_T *)GPIOA_BASE)
#define GPIOB 	((GPIO_T *)GPIOB_BASE)
#define GPIOC 	((GPIO_T *)GPIOC_BASE)
#define GPIOD 	((GPIO_T *)GPIOD_BASE)
#define GPIOE 	((GPIO_T *)GPIOE_BASE)

//AFIO
#define AFIO 	((AFIO_T *)AFIO_BASE)

//EXTI
#define EXTI 	((EXTI_T *)EXTI_BASE)
//================================================

//-----------------------------
//clock enable Macros
//-----------------------------

//GPIO
#define RCC_GPIOA_CLK_EN() SETBIT(RCC->APB2ENR,2)
#define RCC_GPIOB_CLK_EN() SETBIT(RCC->APB2ENR,3)
#define RCC_GPIOC_CLK_EN() SETBIT(RCC->APB2ENR,4)
#define RCC_GPIOD_CLK_EN() SETBIT(RCC->APB2ENR,5)
#define RCC_GPIOE_CLK_EN() SETBIT(RCC->APB2ENR,6)

//AFIO
#define RCC_AFIO_CLK_EN() SETBIT(RCC->APB2ENR,0)
//================================================

#endif /* INC_STM32F103X6_H_ */
