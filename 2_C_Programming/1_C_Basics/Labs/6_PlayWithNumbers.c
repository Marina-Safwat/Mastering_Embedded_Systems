/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 */

#include <stdio.h>
int main()
{
	//get the number of students
	int i ,j;
	for(i = 0;i < 10;i++)
	{
		for(j=i;j<10;j++)
		{
			printf("%d ",j);
		}
		printf("\n");
	}
}
