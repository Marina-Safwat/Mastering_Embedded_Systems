/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 *
EX7:

it is an interview trick

Write Source Code to Swap Two Numbers without temp variable.

 */

#include <stdio.h>
int main()
{
	//get two numbers
	int num1,num2;
	printf("Enter value of a : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num1);

	printf("Enter value of b : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num2);

	num1+=num2;
	num2=(num1-num2);
	num1-=num2;
	printf("After swapping, value of a = %d\n",num1);
	printf("After swapping, value of b = %d",num2);
}
