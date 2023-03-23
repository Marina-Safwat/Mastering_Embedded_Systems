/*
 * 4_arrayInsert.c
 *
 *  Created on: Mar 23, 2023
 *      Author: Marina
  EX4:
 	 write a c program to insert an element in an array
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

	//insert element
	int element,location;
	printf("Enter the element to be inserted : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&element);
	printf("Enter the location : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&location);

	// print array after insertion
	for(i=0; i <num;i++)
	{
		if(i==(location-1))
		{
			printf("%d ",element);
		}
		printf("%d ",arr[i]);
	}
}
