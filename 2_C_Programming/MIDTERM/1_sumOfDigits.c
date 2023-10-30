/*
 * sumOfDigits.c
 *
 *  Created on: oct 29, 2023
 *      Author: Marina
 */

#include <stdio.h>

int sumOfDigits(int n);

int main()
{
	int n;
	printf("Please Enter the number: ");
	scanf("%d",&n);
	printf("The sum of digits of the number %d is %d\n",n,sumOfDigits(n));
}

int sumOfDigits(int n)
{
	if(n == 0)
		return 0;
	else{
		return (n%10)+sumOfDigits(n/10);
	}
}