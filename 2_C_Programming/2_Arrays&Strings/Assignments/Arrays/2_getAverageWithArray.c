/*
 * 2_getAverageWithArray.c
 *
 *  Created on: Mar 23, 2023
 *      Author: Marina
 EX2:
 	 write a c program to find sum of two matrices of order 2*2 using multidimensional arrays
 */

#include <stdio.h>

int main()
{
	//get the number of elements
	int num;
	printf("Enter the numbers of data : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	//get elements into array
	float data[1000];
	int i;
	float sum =0;
	for(i = 0;i < num;i++)
	{
		printf("%d. Enter number : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&data[i]);
		sum+=data[i];
	}

	//calculate the average
	sum/=num;
	printf("Average = %.2f",sum);
}
