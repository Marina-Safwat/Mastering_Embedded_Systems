/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 *
EX3:

Write C Program to Add Two Integers

i should see the Console as following:
##########Console-output###
Enter two integers: 12
11
Sum: 23

 */

#include <stdio.h>
int main()
{
	//get two numbers
	int num1,num2;
	printf("Enter first integer : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num1);

	printf("Enter second integer : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num2);

	printf("sum %d",num1+num2);
}
