/*
 * addComplex.c
 *
 *  Created on: nov 1, 2023
 *      Author: Marina
 */

#include <stdio.h>

struct SDistance
{
	int feet;
	float inch;
};

struct SDistance GetDistance();
struct SDistance AddDistance(struct SDistance a,struct SDistance b);
void PrintSum(struct SDistance a);

int main()
{
	struct SDistance x,y,z;
	printf("Enter information for 1st distance:\n");
	x = GetDistance();
	printf("Enter information for 2nd distance:\n");
	y = GetDistance();
	z = AddDistance(x,y);
	PrintSum(z);
}

struct SDistance GetDistance()
{
	struct SDistance a;
	printf("Enter feet:");
	scanf("%d",&a.feet);
	printf("Enter inch:");
	scanf("%f",&a.inch);
	return a;
}

struct SDistance AddDistance(struct SDistance a,struct SDistance b)
{
	struct SDistance c;
	c.feet = a.feet + b.feet;
	c.inch = a.inch + b.inch;
	while(c.inch>12.0)
	{
		c.inch-=12.0;
		c.feet++;
	}
	return c;
}

void PrintSum(struct SDistance a)
{
	printf("Sum of distances = %d\'-%.1f\"\n",a.feet,a.inch);
}