/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
EX2:
Write C Program to find the largest number among 3 numbers
 */
#include <stdio.h>
int main()
{
	//get three numbers
	float num1,num2,num3;
	printf("Enter number 1 : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num1);

	printf("Enter number 2 : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num2);

	printf("Enter number 3 : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num3);

	//calculate the largest
	if(num1 > num2)
	{
		if(num1 > num3)
			printf("The largest value is %f",num1);
		else
			printf("The largest value is %f",num3);
	}
	else
		if(num2 > num3)
			printf("The largest value is %f",num2);
		else
			printf("The largest value is %f",num3);
}
