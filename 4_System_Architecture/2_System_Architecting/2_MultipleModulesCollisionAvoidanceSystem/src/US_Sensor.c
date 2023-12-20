// collision avoidance program implementation
// by Marina Safwat
// 14/12/2023

#include "US_Sensor.h"

int distance = 0;

void(*P_US_State)();

stDefine(US_init)
{
	//init US Sensor
	//call US drivers & functions
	printf("US_init\n");
}

stDefine(US_reading)
{
	//put state ID
	US_state_ID = US_Reading;

	
	//state action
	//getting sensor reads
	distance = generateRandom(45,55);
	
	//printing status
	printf("US Reading State sent distance = %d\n",distance);
	
	//set next state
	P_US_State = st(US_reading);
	
	//send distance 
	USSetDistance(distance);
}


int generateRandom(int l,int r)
{
	int rand_num = ((rand() % (r - l + 1)) + l);
}