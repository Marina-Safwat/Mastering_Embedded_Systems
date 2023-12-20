// collision avoidance program implementation
// by Marina Safwat
// 14/12/2023

#include "DC_Motor.h"

int speed = 0;

void(*P_DC_State)();

//connection written in distination
void CASetSpeed(int s)
{
	speed = s;
	P_DC_State = st(DC_busy);
	
	//print status
	printf("CA ----------speed = %d----------> DC\n",speed);
}

stDefine(DC_init)
{
	//init DC Sensor
	//call DC drivers & functions
	printf("DC_init\n");
}

stDefine(DC_idle)
{
	//put state ID
	DC_state_ID = DC_Idle;
	
	//printing status
	printf("Idle State : speed = %d\n",speed);
	
	//set next state same because there isn't an event to go to busy
	P_DC_State = st(DC_idle);
}

stDefine(DC_busy)
{
	//put state ID
	DC_state_ID = DC_Busy;
	
	//printing status
	printf("Busy State : speed = %d\n",speed);
	
	//go to idle state
	P_DC_State = st(DC_idle);
}