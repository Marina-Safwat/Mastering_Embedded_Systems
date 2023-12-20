// collision avoidance program header
// by Marina Safwat
// 14/12/2023

#ifndef CA_H_
#define CA_H_

#include "state.h"

extern void(*PState)();

enum {
	CA_Waiting,
	CA_Driving
}CA_state_ID;

stDefine(CA_waiting);
stDefine(CA_driving);
int generateRandom();

#endif