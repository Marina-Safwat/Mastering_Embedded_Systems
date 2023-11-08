/*
 * pointerReverseString.c
 *
 *  Created on: nov 8, 2023
 *      Author: Marina
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char str[50];
	char rvstr[50];
	char* ptvs = rvstr;
	printf("Enter the string : ");
	scanf("%s",str);
	char* pts = str+strlen(str)-1;
	while(pts!=str)
	{
		*ptvs = *pts;
		pts--;
		ptvs++;
	}
	*ptvs = *pts;
	ptvs++;
	*ptvs = '\0';
	printf("The string after reverse : %s",rvstr);
	return 0;
}