/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 *
EX2:
Write C Program to check Whether a character is Vowel or Consonant
 */

#include <stdio.h>
int main()
{
	//get character
	char c;
	printf("Enter an alphabet : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&c);

	switch(c)
	{
	case 'a':
	case 'A':
	case 'o':
	case 'O':
	case 'e':
	case 'E':
	case 'i':
	case 'I':
	case 'u':
	case 'U':
		printf("%c is a vowel",c);
		break;
	default:
		printf("%c is a consonant",c);
		break;
	}
}
