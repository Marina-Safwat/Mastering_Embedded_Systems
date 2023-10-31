/*
 * addComplex.c
 *
 *  Created on: oct 30, 2023
 *      Author: Marina
 */

#include <stdio.h>

struct Scomplex
{
	double R;
	double I;
};

struct Scomplex ReadComplex(char name[]);
struct Scomplex AddComplex(struct Scomplex a,struct Scomplex b);
void PrintComplex(char name[],struct Scomplex a);

int main()
{
	struct Scomplex x,y,z;
	x = ReadComplex("X");
	y = ReadComplex("Y");
	z = AddComplex(x,y);
	PrintComplex("Z",z);
}

struct Scomplex ReadComplex(char name[])
{
	struct Scomplex a;
	printf("Enter the %s complex number as(5 3) :",name);
	scanf("%lf %lf",&a.R,&a.I);
	return a;
}

struct Scomplex AddComplex(struct Scomplex a,struct Scomplex b)
{
	struct Scomplex c;
	printf("%lf,%lf,%lf,%lf",a.R,a.I,b.R,b.I);
	c.R = a.R + b.R;
	c.I = a.I + b.I;
	return c;
}

void PrintComplex(char name[],struct Scomplex a)
{
	printf("%s = (%lf) + j (%lf)\n",name,a.R,a.I);
}