// collision avoidance program implementation
// by Marina Safwat
// 14/12/2023

#include "CA.h"

int CAdistance = 0;
int CAspeed = 0;
int threshold = 50;

void(*P_CA_State)();

//connection written in distination
void USSetDistance(int d)
{
	//set the value
	CAdistance = d;
	
	//checking of the value to determine next state
	(CAdistance<=threshold)?(P_CA_State = st(CA_waiting)):(P_CA_State = st(CA_driving));
	
	//print status
	printf("US ---------Distance = %d---------> CA\n",CAdistance);
}

stDefine(CA_waiting)
{
	//put state ID
	CA_state_ID = CA_Waiting;
	
	//state action
	CAspeed = 0;
	

	//printing status
	printf("Waiting State : distance = %d speed = %d\n",CAdistance,CAspeed);
	
	//state action send data
	CASetSpeed(CAspeed);
}

stDefine(CA_driving)
{
	//put state ID
	CA_state_ID = CA_Driving;
	
	//state action
	CAspeed = 30; //DC_Motor(speed)
	
	//printing status
	printf("Driving State : distance = %d speed = %d\n",CAdistance,CAspeed);
	
	//state action send data
	CASetSpeed(CAspeed);
}