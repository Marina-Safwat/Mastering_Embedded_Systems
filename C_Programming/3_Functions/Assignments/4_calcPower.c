/*
 * calculatePower.c
 *
 *  Created on: oct 19, 2023
 *      Author: Marina
 */
 
#include <stdio.h>
#include <string.h>

int getPower(int n,int x);

int main()
{
	int n,x;
	printf("Enter the base number : ");
	scanf("%d",&n);
	printf("Enter the power number (positive): ");
	scanf("%d",&x);
	printf("%d ^ %d = %d\n",n,x,getPower(n,x));
	return 0;
}

int getPower(int n,int x)
{
	int res = 1;
	for(int i = 0;i<x;i++)
	{
		res*=n;
	}
	return res;
}