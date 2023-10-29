/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 */

#include <stdio.h>
int main()
{
	//get the number of students
	int n;
	printf("Enter the number of students : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);

	//get students degrees
	int i,sum =0;
	for(i = 0;i < n;i++)
	{
		int stdegree;
		printf("Enter student %d degree : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",&stdegree);
		sum += stdegree;
	}

	//get the average
	float average = sum*1.0;
	average/=n;
	printf("Average students degree is %f",average);
}
