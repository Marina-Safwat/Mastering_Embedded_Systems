/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 *
EX2:

Write C Program to Print a Integer Entered by a User
i should see the Console as following:
##########Console-output###
Enter a integer: 25
You entered: 25

 */

#include <stdio.h>
int main()
{
	//get the number
	int n;
	printf("Enter a integer : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);

	printf("you entered %d",n);
}
