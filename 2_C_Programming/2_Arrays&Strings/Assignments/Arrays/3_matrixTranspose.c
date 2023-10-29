/*
 * 3_matrixTranspose.c
 *
 *  Created on: Mar 23, 2023
 *      Author: Marina
  EX3:
 	 write a c program to find Transpose of a matrix
 */

#include <stdio.h>

int main()
{
	//get the matrix order
	int rows,colomns,i,j;
	printf("Enter number of rows of the matrix : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&rows);

	printf("Enter number of colomns of the matrix : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&colomns);

	//get matrix data
	printf("Enter elements of the matrix : \n");
	int matrix[100][100];
	for(i = 0;i < rows;i++)
	{
		for(j = 0;j < colomns;j++)
		{
			printf("Enter the element a%d%d :",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%d",&matrix[i][j]);
		}
	}

	//print entered matrix
	printf("Entered Matrix : \n");
	for(i =0;i<rows;i++)
	{
		for(j=0; j <colomns;j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}

	//print transpose matrix
	printf("Transposed Matrix : \n");
	for(i =0;i<colomns;i++)
	{
		for(j=0; j <rows;j++)
		{
			printf("%d ",matrix[j][i]);
		}
		printf("\n");
	}
}
