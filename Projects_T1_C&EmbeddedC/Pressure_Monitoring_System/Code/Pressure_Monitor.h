/*************************************************************************/
// Author        : Marina Safwat Barsoum Gerges
// Project       : Pressure_Monitoring_System_Project
// File          : Pressure_Monitor.h
// Date          : Dec 29, 2023
// GitHub        : https://github.com/Marina-Safwat
/*************************************************************************/

#ifndef PRESSURE_MONITOR_H_
#define PRESSURE_MONITOR_H_

#include "State.h"

#define PressureThreshold 20

extern void (*P_PM_State)();

enum{
	PM_checking
}PM_State_ID;

STATE_DEFINE(PM_CHECK);
void setPressure(uint32 Pressure);

#endif /* PRESSURE_MONITOR_H_ */
