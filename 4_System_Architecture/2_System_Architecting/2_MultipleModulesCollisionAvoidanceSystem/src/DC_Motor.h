// collision avoidance program header
// by Marina Safwat
// 14/12/2023

#ifndef _DC_MOTOR_H_
#define _DC_MOTOR_H_

#include "state.h"

extern void(*P_DC_State)();

enum {
	DC_Idle,
	DC_Busy
}DC_state_ID;

stDefine(DC_init);
stDefine(DC_idle);
stDefine(DC_busy);

#endif