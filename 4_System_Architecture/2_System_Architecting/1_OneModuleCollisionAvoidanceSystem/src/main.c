// main function for collision avoidance program
// by Marina Safwat
// 14/12/2023

#include "CA.h"

void setup()
{
	//all drivers initiation
	
	//set states pointers for each block
	PState = st(CA_waiting);
}

int main()
{
	volatile int d;
	
	setup();
	while(1)
	{
		//call all blocks pointers
		PState();
		
		//delay
		for(d = 0;d <= 1000;d++){}
	}
	return 0;
}