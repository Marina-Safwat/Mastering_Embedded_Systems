/*
 * 6_charFrequency.c
 *
 *  Created on: Mar 23, 2023
 *      Author: Marina
  EX1:
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

	//get character to get frequency
	char c;
	printf("Enter a character to find frequency : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&c);

	// calculate frequency
	int i,cnt =0;
	for(i=0; i <strlen(str);i++)
	{
		if(str[i]==c)cnt++;
	}
	printf("Frequency of %c = %d \n",c,cnt);
}
