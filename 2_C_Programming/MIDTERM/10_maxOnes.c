/*
 * maxOnes.c
 *
 *  Created on: oct 30, 2023
 *      Author: Marina
 */

#include <stdio.h>
#include <string.h>

int maxOnes(int n);

int main()
{
	int n;
	printf("Enter the number : ");
	scanf("%d",&n);
	printf("The max number of ones between zeros is %d",maxOnes(n));
}

int maxOnes(int n)
{
	int count = 0;
	while(n)
	{
		n=(n&(n<<1));
		count++;
	}
	return count;
}