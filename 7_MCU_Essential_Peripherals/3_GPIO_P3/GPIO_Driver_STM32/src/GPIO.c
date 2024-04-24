/*
 * GPIO.c
 *
 *  Created on: Apr 22, 2024
 *      Author: Marina
 */

//Includes
#include "STM32F103x6.h"
#include "GPIO.h"

uint8_t GET_CR_POSITION(uint16_t PIN_NUM){
	return (PIN_NUM % 8) * 4;
}

/**================================================================
 * @Fn_name		-	MCAL_GPIO_Init
 * @brief 		-	Initialize GPIOx PINy according to the configuration
 * 					information in pin_config sent by the user
 * @param [in]	-	GPIOx the GPIO that include the pin to initialize (A..E)
 * @param [in] 	-	pin_config pointer that has configuration information
 * 					of specified pin
 * @retval 		-	void
 * Note			-	STM32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 					But LQFP48 Package has only GPIO A,B,PART of
 * 					C/D exported as external PINs from the MCU
 */
void MCAL_GPIO_Init(GPIO_T * GPIOx,PIN_CONFIG * PIN){
	//get which configuration port we will work with

	//Port configuration register low (GPIOx_CRL) (x=A..G) from 0 >>> 7
	//Port configuration register high (GPIOx_CRH) (x=A..G) from 8 >>> 15
	volatile uint32_t * config_reg = NULL;
	config_reg = (PIN->PIN_NUM < PIN_NUM_8)? &GPIOx->CRL : &GPIOx->CRH;

	//get the position of start of its configuration bits
	uint8_t position = GET_CR_POSITION(PIN->PIN_NUM);

	uint8_t config_value;

	//clear CNFy[1:0] MODEy[1:0]
	CLR_4_BIT(*config_reg,position);

	//if PIN is output
	if(PIN->PIN_MODE > PIN_MODE_IN_ALT){
		config_value = ((((PIN->PIN_MODE-5)<<2)|(PIN->PIN_OUT_SPEED&0b11))& 0x0f);
	}
	//if PIN is input
	else{
		if(PIN->PIN_MODE < PIN_MODE_IN_PU){
			config_value = (((PIN->PIN_MODE)<<2)& 0x0f);
		}else if(PIN->PIN_MODE == PIN_MODE_IN_ALT){
			config_value = ((PIN_MODE_IN_FLO<<2)& 0x0f);
		}else{
			config_value = (((PIN_MODE_IN_PU)<<2)& 0x0f);
			if(PIN->PIN_MODE == PIN_MODE_IN_PU){
				//PxODR = 1 Input pull-up :Table 20. Port bit configuration table
				SETBIT(GPIOx->ODR,PIN->PIN_NUM);
			}else{
				//PxODR = 0 Input pull-down :Table 20. Port bit configuration table
				CLRBIT(GPIOx->ODR,PIN->PIN_NUM);
			}
		}
	}
	WRT_4_BIT(*config_reg,config_value,position);
}

/**================================================================
 * @Fn_name		-	MCAL_GPIO_RESET_PORT
 * @brief 		-	reset specific port registers
 * @param [in]	-	GPIOx the GPIO to reset
 * @retval 		-	void
 * Note			-	None
 */
void MCAL_GPIO_DEINIT_PORT(GPIO_T * GPIOx){
	//you can reset each register to its reset value

	//or you can use the reset controller
	//APB2 peripheral reset register ()
	//set and cleared by software to work
	if(GPIOx == GPIOA){
		SETBIT(RCC->APB2RSTR,2);
		CLRBIT(RCC->APB2RSTR,2);
	}else if(GPIOx == GPIOB){
		SETBIT(RCC->APB2RSTR,3);
		CLRBIT(RCC->APB2RSTR,3);
	}else if(GPIOx == GPIOC){
		SETBIT(RCC->APB2RSTR,4);
		CLRBIT(RCC->APB2RSTR,4);
	}else if(GPIOx == GPIOD){
		SETBIT(RCC->APB2RSTR,5);
		CLRBIT(RCC->APB2RSTR,5);
	}else if(GPIOx == GPIOE){
		SETBIT(RCC->APB2RSTR,6);
		CLRBIT(RCC->APB2RSTR,6);
	}
}

/**================================================================
 * @Fn_name		-	MCAL_GPIO_RESET_PORT
 * @brief 		-	reset specific port values
 * @param [in]	-	GPIOx the GPIO to reset
 * @retval 		-	void
 * Note			-	None
 */
void MCAL_GPIO_RESET_PORT(GPIO_T * GPIOx){

}
/**================================================================
 * @Fn_name		-	MCAL_GPIO_RESET_BIT
 * @brief 		-	reset specific bit
 * @param [in]	-	GPIOx the GPIO that include the pin to reset
 * @param [in] 	-	Number of the pin to be reset
 * @retval 		-	void
 * Note			-	PIN_NUM from @ref PIN_NUM_define
 */
void MCAL_GPIO_RESET_BIT(GPIO_T * GPIOx,uint16_t PIN_NUM){

}

/**================================================================
 * @Fn_name		-	MCAL_GPIO_READ_PIN
 * @brief 		-	get a specific pin value
 * @param [in]	-	GPIOx the GPIO that include the pin that hold the value
 * @param [in] 	-	Number of the pin that hold the value
 * @retval 		-	uint8_t that hold the value of the pin(Input Pin) VALUE from @ref PIN_VALUE
 * Note			-	PIN_NUM from @ref PIN_NUM_define
 */
uint8_t MCAL_GPIO_READ_PIN(GPIO_T * GPIOx,uint16_t PIN_NUM){
	return GETBIT(GPIOx->IDR,PIN_NUM);
}

/**================================================================
 * @Fn_name		-	MCAL_GPIO_READ_PORT
 * @brief 		-	get port value
 * @param [in]	-	GPIOx the GPIO to get its value
 * @retval 		-	uint16_t that hold the value of the port
 * Note			-	None
 */
uint16_t MCAL_GPIO_READ_PORT(GPIO_T * GPIOx){
	return (uint16_t)GPIOx->IDR;
}

/**================================================================
 * @Fn_name		-	MCAL_GPIO_WRITE_PIN
 * @brief 		-	write a specific value on specific pin
 * @param [in]	-	GPIOx the GPIO that include the pin
 * @param [in] 	-	Number of the pin
 * @param [in] 	-	the value to add
 * @retval 		-	void
 * Note			-	PIN_NUM from @ref PIN_NUM_define
 * 					VALUE from @ref PIN_VALUE
 */
void MCAL_GPIO_WRITE_PIN(GPIO_T * GPIOx,uint16_t PIN_NUM,uint8_t VALUE){
	if(VALUE){
		SETBIT(GPIOx->ODR,PIN_NUM);
	}else{
		CLRBIT(GPIOx->ODR,PIN_NUM);
	}
}

/**================================================================
 * @Fn_name		-	MCAL_GPIO_WRITE_PORT
 * @brief 		-	write a specific value on specific output PORT
 * @param [in]	-	GPIOx the GPIO to add value
 * @param [in] 	-	the value to add
 * @retval 		-	void
 * Note			-	None
 */
void MCAL_GPIO_WRITE_PORT(GPIO_T * GPIOx,uint16_t VALUE){
	GPIOx->ODR = (uint32_t) VALUE;
}

/**================================================================
 * @Fn_name		-	MCAL_GPIO_TOGGLE_PIN
 * @brief 		-	toggle a specific pin
 * @param [in]	-	GPIOx the GPIO that include the pin
 * @param [in] 	-	Number of the pin
 * @retval 		-	void
 * Note			-	PIN_NUM from @ref PIN_NUM_define
 */
void MCAL_GPIO_TOGGLE_PIN(GPIO_T * GPIOx,uint32_t PIN_NUM){
	TGLBIT(GPIOx->ODR,PIN_NUM);
}

/**================================================================
 * @Fn_name		-	MCAL_GPIO_TOGGLE_PIN
 * @brief 		-	lock configuration of specific pin
 * @param [in]	-	GPIOx the GPIO that include the pin
 * @param [in] 	-	Number of the pin
 * @retval 		-	return OK if lock done successfully and ERROR else
 * 					@ref STATUS_define
 * Note			-	PIN_NUM from @ref PIN_NUM_define
 */
uint8_t MCAL_GPIO_LOCK_PIN(GPIO_T * GPIOx,uint32_t PIN_NUM){
	/*
	LOCK key writing sequence:
	Write 1
	Write 0
	Write 1
	Read 0
	Read 1 (this read is optional but confirms that the lock is active)
	 */
	SETBIT(GPIOx->LCKR,PIN_NUM);
	SETBIT(GPIOx->LCKR,16);
	CLRBIT(GPIOx->LCKR,16);
	SETBIT(GPIOx->LCKR,16);

	if(GETBIT(GPIOx->LCKR,16)==0){
		if(GETBIT(GPIOx->LCKR,16)){
			return STATUS_OK;
		}
	}
	return STATUS_ERROR;
}
