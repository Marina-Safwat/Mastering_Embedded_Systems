/*
 * pointersInProgram.c
 *
 *  Created on: nov 8, 2023
 *      Author: Marina
 */

#include <stdio.h>

int main()
{
	int m;
	m = 29;
	printf("Address of m : %x\n",&m);
	printf("Value of m : %d\n",m);
	
	int* ab = &m;
	printf("Now ab is assigned with the address of m.\n");
	printf("Address of pointer ab : %x\n",ab);
	printf("Value of poiinter ab : %d\n",*ab);
	
	m = 34;
	printf("The value of m assigned to 34 now.\n");
	printf("Address of pointer ab : %x\n",ab);
	printf("Value of poiinter ab : %d\n",*ab);
	
	*ab = 7;
	printf("The pointer variable ab is assigned with the value 7 now.\n");
	printf("Address of m : %x\n",&m);
	printf("Value of m : %d\n",m);
	return 0;
}