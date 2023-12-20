// main function for collision avoidance program
// by Marina Safwat
// 14/12/2023

#include "CA.h"
#include "US_Sensor.h"
#include "DC_Motor.h"

void setup()
{
	//all drivers initiation
	st(US_init)();
	st(DC_init)();
	
	//set states pointers for each block
	P_US_State = st(US_reading);
	P_CA_State = st(CA_waiting);
	P_DC_State = st(DC_idle);
}

int main()
{
	volatile int d;
	
	setup();
	while(1)
	{
		//call all blocks pointers
		P_US_State();
		P_CA_State();
		P_DC_State();
		
		//delay
		for(d = 0;d <= 1000;d++);
	}
	return 0;
}