/*
 * main.c
 *
 *  Created on: sep 15, 2023
 *      Author: Marina
 */
 
#include <stdio.h>

int main()
{
	float degrees[10];
	for(int i =0;i <10;i++)
	{
		printf("Enter Student %d degree : ",i+1);
		scanf("%f",&degrees[i]);
	}
	for(int i =0;i<10;i++)
	{
		printf("Student %d degree is %f\n",i+1,degrees[i]);
	}
	return 0;
}