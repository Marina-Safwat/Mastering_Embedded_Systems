/*
 * factorial.c
 *
 *  Created on: oct 19, 2023
 *      Author: Marina
 */
 
#include <stdio.h>

int fact (int x);

int main()
{
	int n;
	printf("Enter the number to get its factorial:");
	scanf("%d",&n);
	printf("The factorial of %d is %d\n",n,fact(n));
	return 0;
}

int fact (int x)
{
	if(x>1)
		return x*fact(x-1);
	else
		return 1;
}