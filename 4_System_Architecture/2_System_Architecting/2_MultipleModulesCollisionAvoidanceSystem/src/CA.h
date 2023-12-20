// collision avoidance program header
// by Marina Safwat
// 14/12/2023

#ifndef _CA_H_
#define _CA_H_

#include "state.h"

extern void(*P_CA_State)();

enum {
	CA_Waiting,
	CA_Driving
}CA_state_ID;

stDefine(CA_waiting);
stDefine(CA_driving);

#endif