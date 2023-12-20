// collision avoidance program header
// by Marina Safwat
// 14/12/2023

#ifndef _US_SENSOR_H_
#define _US_SENSOR_H_

#include "state.h"

extern void(*P_US_State)();

enum {
	US_Reading,
}US_state_ID;

stDefine(US_init);
stDefine(US_reading);
int generateRandom();

#endif