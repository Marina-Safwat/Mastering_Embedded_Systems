/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 */
#include <stdio.h>
int main()
{
	//get circle radius
	float radius;
	printf("Enter circle radius : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&radius);

	//get user choice
	char choice;
	printf("Enter your choice (a to print the area, c to print the circumference) : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&choice);

	//apply the choice
	if(choice == 'a')
		printf("the area is %f",3.14*radius*radius);
	else if (choice == 'c')
		printf("the circumference is %f",3.14*2*radius);
	else
		printf("wrong choice!");
}

