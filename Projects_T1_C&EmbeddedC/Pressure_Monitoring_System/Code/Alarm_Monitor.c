/*************************************************************************/
// Author        : Marina Safwat Barsoum Gerges
// Project       : Pressure_Monitoring_System_Project
// File          : Alarm_Monitor.c
// Date          : Dec 29, 2023
// GitHub        : https://github.com/Marina-Safwat
/*************************************************************************/

#include "Alarm_Monitor.h"

//put alarm duration
uint32 AlarmTimer = ALARM;

//pointer to Alarm_Monitor states
void (*P_AM_State)();

//connection functions
void HighPressureDetected()
{
	//put the next state is to turn the alarm on
	P_AM_State = STATE(AM_ON);
}

//states functions
STATE_DEFINE(AM_OFF)
{
	//set state ID
	AM_State_ID = AM_off;
	
	//stop the alarm
	StopAlarm();
}

STATE_DEFINE(AM_ON)
{
	//set state ID
	AM_State_ID = AM_on;
	
	//start the alarm
	StartAlarm();
	
	//delay as timer duration
	Delay(AlarmTimer);
	
	//go for off alarm
	P_AM_State = STATE(AM_OFF);
}