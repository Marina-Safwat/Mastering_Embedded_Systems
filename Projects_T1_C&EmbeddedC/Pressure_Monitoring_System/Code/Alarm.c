/*************************************************************************/
// Author        : Marina Safwat Barsoum Gerges
// Project       : Pressure_Monitoring_System_Project
// File          : Alarm.h
// Date          : Dec 29, 2023
// GitHub        : https://github.com/Marina-Safwat
/*************************************************************************/

#include "Alarm.h"

//pointer to alarm states
void (*P_A_State)();

//connection functions
void StartAlarm()
{
	P_A_State = STATE(A_ON);
}

void StopAlarm()
{
	P_A_State = STATE(A_OFF);
}

//state functions
STATE_DEFINE(A_INIT)
{
	//set state ID
	A_State_ID = A_init;
	
	//init gpio
	GPIO_INITIALIZATION();
	
	//turn the led off
	SET_BIT(GPIOA_ODR,13); //(Active Low)
	
	//go for waiting
	P_A_State = STATE(A_WAITING);
}

STATE_DEFINE(A_WAITING)
{
	//set state ID
	A_State_ID = A_Waiting;
}

STATE_DEFINE(A_ON)
{
	//set state ID
	A_State_ID = A_on;
	
	//turn the led on
	RESET_BIT(GPIOA_ODR,13); //(Active Low)
	
	//go for waiting
	P_A_State = STATE(A_WAITING);
}

STATE_DEFINE(A_OFF)
{
	//set state ID
	A_State_ID = A_off;
	
	//turn the led off
	SET_BIT(GPIOA_ODR,13); //(Active Low)
	
	//go for waiting
	P_A_State = STATE(A_WAITING);
}