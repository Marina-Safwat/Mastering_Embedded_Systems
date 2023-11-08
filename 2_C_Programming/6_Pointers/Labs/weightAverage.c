/*
 * weightAverage.c
 *
 *  Created on: nov 8, 2023
 *      Author: Marina
 */

#include <stdio.h>

int main()
{
	int x[5];
	int sum = 0;
	int* px = x;
	for(int i = 0;i < 5;i++)
	{
		scanf("%d",px+i);
	}
	for(int i = 0;i < 5;i++)
		sum+=*px++;
	sum/=5;
	printf("Average = %d\n",sum);
	return 0;
}