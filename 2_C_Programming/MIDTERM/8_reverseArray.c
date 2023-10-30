/*
 * reverseArray.c
 *
 *  Created on: oct 29, 2023
 *      Author: Marina
 */

#include <stdio.h>

void reverseArray(int arr[],int n);

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
	reverseArray(arr,n);
	printf("The array after reverse: ");
	for(int i =0; i <n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void reverseArray(int arr[],int n)
{
	int i=0,j=n-1;
	int temp;
	while(i<j)
	{
		temp = arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		i++;j--;
	}
}