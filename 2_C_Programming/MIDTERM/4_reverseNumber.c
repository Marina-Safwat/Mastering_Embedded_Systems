/*
 * reverseNumber.c
 *
 *  Created on: oct 29, 2023
 *      Author: Marina
 */

#include <stdio.h>

int reverseNumber(int n);

int main()
{
	int n;
	printf("Please Enter the number: ");
	scanf("%d",&n);
	printf("The reverse is %d\n",reverseNumber(n));
}

int reverseNumber(int n)
{
	int res = 0;
	while(n!=0)
	{
		res*=10;
		res+=n%10;
		n/=10;
	}
	return res;
}