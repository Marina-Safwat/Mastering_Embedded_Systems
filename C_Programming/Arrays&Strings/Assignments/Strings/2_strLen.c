/*
 * 2_strLen.c
 *
 *  Created on: Mar 23, 2023
 *      Author: Marina
 EX2:
 	 write a c program to find the frequency of characters in a string
 */

#include <stdio.h>
#include <string.h>

int main()
{
	//get the string
	char str[100];
	printf("Enter a string : ");
	fflush(stdin);fflush(stdout);
	gets(str);

	// get length of the string
	int i,len =0;
	for(i=0; str[i] != 0;i++)len++;
	printf("length of string = %d \n",len);
}

