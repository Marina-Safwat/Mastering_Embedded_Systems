/*
 * uniqueInt.c
 *
 *  Created on: oct 30, 2023
 *      Author: Marina
 */

#include <stdio.h>

int getUnique(int arr[],int n);

int main()
{
	int arr[100],n;
	printf("enter the size of the array: ");
	scanf("%d",&n);
	printf("enter the array: ");
	for(int i =0; i <n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("The unique number in the array is : %d\n",getUnique(arr,n));
}

int getUnique(int arr[],int n)
{
	int res=0;
	for(int i =0; i <n;i++)
	{
		res^=arr[i];
	}
	return res;
}