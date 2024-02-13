/*************************************************************************/
// Author        : Marina Safwat Barsoum Gerges
// Project       : Pressure_Monitoring_System_Project
// File          : Pressure_Sensor.h
// Date          : Dec 29, 2023
// GitHub        : https://github.com/Marina-Safwat
/*************************************************************************/

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "State.h"
#include "GPIO.h"

#define Pressure_Read_period 60000

extern void (*P_PS_State)();

enum{
	PS_init,
	PS_reading,
	PS_waiting
}PS_State_ID;

STATE_DEFINE(PS_INIT);
STATE_DEFINE(PS_READING);
STATE_DEFINE(PS_WAITING);
int getPressureVal();

#endif /* PRESSURE_SENSOR_H_ */
