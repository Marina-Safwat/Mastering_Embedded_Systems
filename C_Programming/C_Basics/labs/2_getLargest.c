/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 */
#include <stdio.h>
int main()
{
	//get three numbers
	int num1,num2,num3;
	printf("Enter number 1 : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num1);

	printf("Enter number 2 : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num2);

	printf("Enter number 3 : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num3);

	//calculate the largest
	if(num1 > num2)
	{
		if(num1 > num3)
			printf("The largest value is %d",num1);
		else
			printf("The largest value is %d",num3);
	}
	else
		if(num2 > num3)
			printf("The largest value is %d",num2);
		else
			printf("The largest value is %d",num3);
}

