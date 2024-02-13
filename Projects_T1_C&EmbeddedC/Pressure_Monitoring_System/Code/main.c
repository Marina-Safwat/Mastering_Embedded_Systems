/*************************************************************************/
// Author        : Marina Safwat Barsoum Gerges
// Project       : Pressure_Monitoring_System_Project
// File          : main.c
// Date          : Dec 29, 2023
// GitHub        : https://github.com/Marina-Safwat
/*************************************************************************/

#include "State.h"
#include "Alarm.h"
#include "Alarm_Monitor.h"
#include "Pressure_Monitor.h"
#include "Pressure_Sensor.h"

void setup()
{
	//all drivers initiation
	STATE(A_INIT)();
	STATE(PS_INIT)();

	//set states pointers for each block
	P_AM_State = STATE(AM_OFF);
	P_PM_State = STATE(PM_CHECK);
}

int main()
{
	setup();
	while(1)
	{
		//call all blocks pointers
		P_PS_State();
		P_PM_State();
		P_AM_State();
		P_A_State();
	}
	return 0;
}
