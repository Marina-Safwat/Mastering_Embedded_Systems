/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 */

#include <stdio.h>
int main()
{
	// get 2 numbers
	int num1,num2;
	printf("Enter first number : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num1);

	printf("Enter second number : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num2);

	//print min
	printf("the minimum is %d",(num1<num2)?num1:num2);
}
