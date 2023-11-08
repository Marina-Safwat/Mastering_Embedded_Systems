/*
 * pointerToStruct.c
 *
 *  Created on: nov 8, 2023
 *      Author: Marina
 */

#include <stdio.h>
#include <string.h>

struct SEmployee
{
	char name[50];
	int ID;
}e1={"marina",21};
int main()
{
	struct SEmployee* ptr = &e1;
	printf("The struct from pointer \n");
	printf("Employee Name : %s\n",ptr->name);
	printf("Employee ID : %d\n",ptr->ID);
	return 0;
}