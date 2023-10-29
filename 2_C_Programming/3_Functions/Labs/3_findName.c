/*
 * findName.c
 *
 *  Created on: oct 19, 2023
 *      Author: Marina
 */
 
#include <stdio.h>
#include <string.h>

void isFound (char arr[][14],int n,char name[]);

int main()
{
	char name[14];
	char arr[100][14];
	int n;
	printf("Enter the size of the list:");
	scanf("%d",&n);
	printf("Enter the names in the list:");
	for(int i =0; i <n;i++)
		scanf("%s",&arr[i]);
	printf("Enter the name to search:");
	scanf("%s",name);
	isFound(arr,n,name);
	return 0;
}

void isFound (char arr[][14],int n,char name[])
{
	for(int i =0; i <n;i++)
	{
		if(!strcmp(name,arr[i]))
		{
			printf("Welcome\n");
			return;
		}
	}
	printf("Not Found\n");
}