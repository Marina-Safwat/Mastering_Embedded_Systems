/*
 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Marina
 *
EX8:
Write C Program to make a simple calculator to Add,Subtract,Multiply or Divide using switch... case
 */

#include <stdio.h>
int main()
{
	//get operator
	char c;
	printf("Enter an operator either + or - or * or divide : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&c);

	float num1,num2;
	printf("Enter first operand : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num1);

	printf("Enter second operand : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num2);

	switch(c)
	{
	case '-':
		printf("%f %c %f = %f",num1,c,num2,num1-num2);
		break;
	case '+':
		printf("%f %c %f = %f",num1,c,num2,num1+num2);
		break;
	case '*':
		printf("%f %c %f = %f",num1,c,num2,num1*num2);
		break;
	case '/':
		printf("%f %c %f = %f",num1,c,num2,num1/num2);
		break;
	default:
		printf("Wrong Operator");
		break;
	}
}
