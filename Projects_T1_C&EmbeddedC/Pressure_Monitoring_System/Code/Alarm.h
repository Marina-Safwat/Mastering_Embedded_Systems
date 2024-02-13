/*************************************************************************/
// Author        : Marina Safwat Barsoum Gerges
// Project       : Pressure_Monitoring_System_Project
// File          : Alarm.h
// Date          : Dec 29, 2023
// GitHub        : https://github.com/Marina-Safwat
/*************************************************************************/

#ifndef ALARM_H_
#define ALARM_H_

#include "State.h"
#include "GPIO.h"
#include "BIT_MATH.h"

extern void (*P_A_State)();

enum{
	A_off,
	A_on,
	A_init,
	A_Waiting
}A_State_ID;

STATE_DEFINE(A_INIT);
STATE_DEFINE(A_WAITING);
STATE_DEFINE(A_ON);
STATE_DEFINE(A_OFF);
void StartAlarm();
void StopAlarm();

#endif /* ALARM_H_ */
