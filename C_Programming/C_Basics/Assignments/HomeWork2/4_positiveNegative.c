/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 *
EX4:
Write C Program to check Whether a number is positive or negative
 */

#include <stdio.h>
int main()
{
	//get number
	int num;
	printf("Enter a number : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	if(num>0)
		printf("%d is Positive",num);
	else if(num<0)
		printf("%d is Negative",num);
	else
		printf("you entered Zero");
}
