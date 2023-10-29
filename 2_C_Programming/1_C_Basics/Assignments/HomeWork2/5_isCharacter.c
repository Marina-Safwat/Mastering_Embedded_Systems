/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 *
EX5:
Write C Program to check Whether a character is Alphabet or not
 */

#include <stdio.h>
int main()
{
	//get character
	char c;
	printf("Enter a character : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&c);

	if((c>='a' && c<='z')||(c>'A' && c<'Z'))
		printf("%c is an alphabet",c);
	else
		printf("%c is not an alphabet",c);
}
