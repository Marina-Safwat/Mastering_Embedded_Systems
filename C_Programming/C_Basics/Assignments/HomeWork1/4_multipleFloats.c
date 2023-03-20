/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 *
EX4:

Write C Program to Multiply two Floating Point Numbers
i should see the Console as following:
##########Console-output###
Enter two numbers: 2.4
1.1
Product: 2.640000

 */

#include <stdio.h>
int main()
{
	//get two numbers
	float num1,num2;
	printf("Enter first number : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num1);

	printf("Enter second number : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num2);

	printf("Product : %f",num1*num2);
}
