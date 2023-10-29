/*
 * reverseSentence.c
 *
 *  Created on: oct 19, 2023
 *      Author: Marina
 */
 
#include <stdio.h>
#include <string.h>

void reverse (char sent[]);

int main()
{
	char sent[100];
	printf("Enter a sentence under 100 characters :");
	fgets(sent,100,stdin);
	reverse(sent);
	return 0;
}

void reverse (char sent[])
{
	for(int i = strlen(sent)-1;i>=0;i--)
	{
		printf("%c",sent[i]);
	}
}