/*************************************************************************/
// Author        : Marina Safwat Barsoum Gerges
// Project       : Pressure_Monitoring_System_Project
// File          : Pressure_Monitor.c
// Date          : Dec 29, 2023
// GitHub        : https://github.com/Marina-Safwat
/*************************************************************************/

#include "Pressure_Monitor.h"

uint32 PM_Pressure = 0;
uint32 Threshold = PressureThreshold;

void (*P_PM_State)();

//connection functions
void setPressure(uint32 Pressure)
{
	//set the value
	PM_Pressure = Pressure;

	//go to check the pressure
	P_PM_State = STATE(PM_CHECK);
}

//states functions
STATE_DEFINE(PM_CHECK)
{
	//set the state ID
	PM_State_ID = PM_checking;
	
	//check pressure
	if(PM_Pressure > Threshold)
	{
		//inform to turn the alarm on
		HighPressureDetected();
		P_PM_State = STATE(PM_CHECK);
	}
	else
	{
		P_PM_State = STATE(PM_CHECK);
	}
}