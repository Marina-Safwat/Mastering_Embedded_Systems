/*
 * reverseString.c
 *
 *  Created on: oct 30, 2023
 *      Author: Marina
 */

#include <stdio.h>
#include <string.h>

void reverseString(char arr[],int n);

int main()
{
	char arr[50];
	printf("enter string :");
	fgets(arr,50,stdin);
	reverseString(arr,strlen(arr));
}

void reverseString(char arr[],int n)
{
	int i,k=n-1;
	for(i =n-1; i >=0;i--)
	{
		//printf("I'm here");
		if(arr[i]==' ')
		{
			for(int j = i+1;j<k;j++)
			{
				printf("%c",arr[j]);
			}
			k=i;
			printf(" ");
		}
	}
	i=0;
	while(arr[i]!=' ')
	{
		printf("%c",arr[i]);
		i++;
	}
}