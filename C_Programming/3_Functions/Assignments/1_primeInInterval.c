/*
 * primeInInterval.c
 *
 *  Created on: oct 19, 2023
 *      Author: Marina
 */
 
#include <stdio.h>
#include <string.h>

int isPrime (int n);
void PrimeNums (int x, int n);

int main()
{
	int n,x;
	printf("Enter two numbers (the interval):");
	scanf("%d %d",&n,&x);
	PrimeNums(n,x);
	return 0;
}

int isPrime (int n)
{
	for(int i = 2 ; i*i <= n ; i++)
	{
		if(n%i==0)return 0;
	}
	return 1;
}

void PrimeNums (int x, int n)
{
	for(int i = x;i<=n;i++)
	{
		if(isPrime(i))
		{
			printf("%d ",i);
		}
	}
	printf("\n");
}