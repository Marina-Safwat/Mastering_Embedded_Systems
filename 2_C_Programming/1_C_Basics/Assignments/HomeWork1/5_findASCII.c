/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 *
EX5:

Write C Program to Find ASCII Value of a Character
#########Console_output######
Enter a character: G
ASCII value of G = 71

 */

#include <stdio.h>
int main()
{
	//get two numbers
	char c;
	printf("Enter a character : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&c);

	printf("ASCII value of %c = %d",c,c);
}
