/*************************************************************************/
// Author        : Marina Safwat Barsoum Gerges
// Project       : Pressure_Monitoring_System_Project
// File          : Alarm_Monitor.h
// Date          : Dec 29, 2023
// GitHub        : https://github.com/Marina-Safwat
/*************************************************************************/

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "State.h"
#include "Delay.h"

#define ALARM 600000

extern void (*P_AM_State)();

enum{
	AM_off,
	AM_on,
}AM_State_ID;

STATE_DEFINE(AM_ON);
STATE_DEFINE(AM_OFF);
void HighPressureDetected();

#endif /* ALARM_MONITOR_H_ */
