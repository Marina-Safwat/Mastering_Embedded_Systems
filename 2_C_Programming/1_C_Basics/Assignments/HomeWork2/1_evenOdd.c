/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 *
EX1:
Write C Program to check Whether a Number is Even or Odd
 */

#include <stdio.h>
int main()
{
	//get number
	int num;
	printf("Enter an integer you want to check : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	if(num%2==0)
		printf("%d is even",num);
	else
		printf("%d is odd",num);
}
