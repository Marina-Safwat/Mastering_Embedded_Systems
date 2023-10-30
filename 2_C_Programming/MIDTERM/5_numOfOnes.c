/*
 * numOfOnes.c
 *
 *  Created on: oct 29, 2023
 *      Author: Marina
 */

#include <stdio.h>

int countOnes(int n);

int main()
{
	int n;
	printf("Please Enter the number: ");
	scanf("%d",&n);
	printf("The number of ones = %d\n",countOnes(n));
}

int countOnes(int n)
{
	int res = 0;
	while(n!=0)
	{
		res+=(n&1);
		n>>=1;
	}
	return res;
}