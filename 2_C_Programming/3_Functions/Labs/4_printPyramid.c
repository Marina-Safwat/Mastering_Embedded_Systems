/*
 * printPyramid.c
 *
 *  Created on: oct 19, 2023
 *      Author: Marina
 */
 
#include <stdio.h>
#include <string.h>

void pyramid (int x, int n);

int main()
{
	int n;
	printf("Enter the size of the pyramid:");
	scanf("%d",&n);
	pyramid(0,n);
	return 0;
}

void pyramid (int x, int n)
{
	if(x<=n)
	{
		for(int i =x; i <=n;i++)
			printf("%d ",i);
		printf("\n");
		pyramid(x+1,n);
	}
}