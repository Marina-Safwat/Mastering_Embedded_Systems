/*
 * minOfArray.c
 *
 *  Created on: oct 19, 2023
 *      Author: Marina
 */
 
#include <stdio.h>

int min (int arr[],int n);

int main()
{
	int n;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	printf("Enter the array:");
	int arr [10000];
	for(int i =0; i <n;i++)
		scanf("%d",&arr[i]);
	printf("The min element of the array is %d\n",min(arr,n));
	return 0;
}

int min (int arr[],int n)
{
	int min = arr[0];
	for(int i =0; i <n;i++)
		if(arr[i]<min)
			min = arr[i];
		
	return min;
}