/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 *
EX6:

Write Source Code to Swap Two Numbers

#########Console_output######
Enter value of a: 1.20
Enter value of b: 2.45

After swapping, value of a = 2.45
After swapping, value of b = 1.2

 */

#include <stdio.h>
int main()
{
	//get two numbers
	float num1,num2;
	printf("Enter value of a : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num1);

	printf("Enter value of b : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num2);

	float temp = num1;
	num1= num2;
	num2= temp;
	printf("After swapping, value of a = %f\n",num1);
	printf("After swapping, value of b = %f",num2);
}
