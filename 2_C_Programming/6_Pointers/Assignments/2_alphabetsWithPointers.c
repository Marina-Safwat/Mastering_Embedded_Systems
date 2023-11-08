/*
 * alphabetsWithPointers.c
 *
 *  Created on: nov 8, 2023
 *      Author: Marina
 */

#include <stdio.h>

int main()
{
	char alphabet[27];
	char* ptc = alphabet;
	for(int i =0; i < 26;i++)
	{
		*(ptc+i) = 'A'+i;
	}
	for(int i = 0;i<26;i++)
	{
		printf("%c ",*ptc);
		ptc++;
	}
	return 0;
}