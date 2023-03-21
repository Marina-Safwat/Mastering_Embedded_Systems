/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 *
EX7:
Write C Program to check Whether a character is Alphabet or not
 */

#include <stdio.h>
int main()
{
	//get a number
	int num;
	printf("Enter an integer : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	if(num<0)
		printf("Error!!! Factorial of negative number doesn't exist.");
	else
	{
		int i ,result = 1;
		for(i=1;i<=num;i++)result*=i;
		printf("Factorial = %d",result);
	}

}
