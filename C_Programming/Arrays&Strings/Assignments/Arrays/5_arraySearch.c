/*
 * 5_arraySearch.c
 *
 *  Created on: Mar 23, 2023
 *      Author: Marina
  EX5:
 	 write a c program to search an element in an array
 */

#include <stdio.h>

int main()
{
	//get number of elements
	int num;
	printf("Enter no of elements : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	//get elements
	int i;
	int arr[100];
	for(i = 0;i <num;i++)
	{
		scanf("%d",&arr[i]);
	}

	//search element
	int element;
	printf("Enter the element to be searched : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&element);

	// print array after insertion
	for(i=0; i <num;i++)
	{
		if(arr[i]==element)
		{
			printf("Number found at the location = %d \n",i+1);
			break;
		}
	}
	if(i==num)
	{
		printf("The number not in the array ");
	}
}
