/*************************************************************************/
// Author        : Marina Safwat Barsoum Gerges
// Project       : Pressure_Monitoring_System_Project
// File          : State.h
// Date          : Dec 29, 2023
// GitHub        : https://github.com/Marina-Safwat
/*************************************************************************/

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include "stdlib.h"
#include "Platform_Types.h"

//creation states
#define STATE_DEFINE(_ST_NAME_) void ST_##_ST_NAME_()
#define STATE(_ST_NAME_) ST_##_ST_NAME_

//state connections
void setPressure(uint32 Pressure);
void HighPressureDetected();
void StartAlarm();
void StopAlarm();

#endif /* STATE_H_ */
