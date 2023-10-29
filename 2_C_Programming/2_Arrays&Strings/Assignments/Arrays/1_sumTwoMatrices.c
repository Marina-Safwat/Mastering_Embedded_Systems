/*
 * 1_sumTwoMatrices.c
 *
 *  Created on: Mar 23, 2023
 *      Author: Marina
 EX1:
 	 write a c program to find sum of two matrices of order 2*2 using multidimensional arrays
 */

#include <stdio.h>

int main()
{
	//definition two matrices
	float matrix1 [2][2];
	float matrix2 [2][2];

	//get two matrices
	printf("Enter the elements of 1st matrix\n");
	int i,j;
	for(i = 0;i < 2;i++)
	{
		for(j = 0;j < 2;j++)
		{
			printf("Enter a%d%d : ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&matrix1[i][j]);
		}
	}

	printf("Enter the elements of 2nd matrix\n");
	for(i = 0;i < 2;i++)
	{
		for(j = 0;j < 2;j++)
		{
			printf("Enter b%d%d : ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&matrix2[i][j]);
		}
	}

	//get the sum and print it
	printf("sum of the two matrices\n");
	for(i = 0;i < 2;i++)
	{
		for(j = 0;j < 2;j++)
		{
			printf("%.1f ",matrix1[i][j]+matrix2[i][j]);
		}
		printf("\n");
	}
}
