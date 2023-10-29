/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 */
#include <stdio.h>
int main()
{
	int i ,sum = 0;
	for(i = 1;i < 100;i++)sum+=i;
	printf("the summation of numbers from 1 to 99 is %d",sum);
}
