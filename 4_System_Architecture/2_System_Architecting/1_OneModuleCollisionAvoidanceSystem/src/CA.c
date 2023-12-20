// collision avoidance program implementation
// by Marina Safwat
// 14/12/2023

#include "CA.h"

int distance = 0;
int speed = 0;
int threshold = 50;

void(*PState)();

stDefine(CA_waiting)
{
	//put state ID
	CA_state_ID = CA_Waiting;
	
	//state action
	speed = 0;
	
	//printing status
	printf("Waiting State : distance = %d speed = %d\n",distance,speed);
	
	//getting sensor reads
	distance = generateRandom(45,55);
	
	//checking of the value to determine next state
	(distance<=threshold)?(PState = st(CA_waiting)):(PState = st(CA_driving));
}

stDefine(CA_driving)
{
	//put state ID
	CA_state_ID = CA_Driving;
	
	//state action
	speed = 30; //DC_Motor(speed)
	
	//printing status
	printf("Driving State : distance = %d speed = %d\n",distance,speed);
	
	//getting sensor reads
	distance = generateRandom(45,55);
	
	//checking of the value to determine next state
	(distance<=threshold)?(PState = st(CA_waiting)):(PState = st(CA_driving));
}

int generateRandom(int l,int r)
{
	int rand_num = ((rand() % (r - l + 1)) + l);
}