/*************************************************************************/
// Author        : Marina Safwat Barsoum Gerges
// Project       : Pressure_Monitoring_System_Project
// File          : Pressure_Sensor.c
// Date          : Dec 29, 2023
// GitHub        : https://github.com/Marina-Safwat
/*************************************************************************/

#include "Pressure_Sensor.h"

uint32 Pressure = 0;
uint32 PressureSensorTimer = Pressure_Read_period;

//pointer to pressure sensor states
void (*P_PS_State)();

//States functions
STATE_DEFINE(PS_INIT)
{
	//set state ID
	PS_State_ID = PS_init;
	
	//init GPIO
	GPIO_INITIALIZATION();
	
	//go to reading state
	P_PS_State = STATE(PS_READING);
}

STATE_DEFINE(PS_READING)
{
	//set state ID
	PS_State_ID = PS_reading;
	
	//get pressure value
	Pressure = getPressureVal();
	
	//send pressure to be checked
	setPressure(Pressure);
	
	//go to waiting state
	P_PS_State = STATE(PS_WAITING);
}

STATE_DEFINE(PS_WAITING)
{
	//set state ID
	PS_State_ID = PS_waiting;
	
	//delay between each two reads
	Delay(PressureSensorTimer);
	
	//go to reading state
	P_PS_State = STATE(PS_READING);
}

//function to get pressure values from push buttons in simulation
int getPressureVal(){
	return (GPIOA_IDR & 0xFF);
}