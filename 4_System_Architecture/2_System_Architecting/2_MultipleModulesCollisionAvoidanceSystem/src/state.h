// state header file
// by Marina Safwat
// 14/12/2023

#ifndef _STATE_H_
#define _STATE_H_

#include "stdlib.h"
#include "stdio.h"

//Automatic state function generator
#define stDefine(_statename_) void ST_##_statename_()
#define st(_statename_) ST_##_statename_

//states connections
void USSetDistance(int d);
void CASetSpeed(int s);

#endif