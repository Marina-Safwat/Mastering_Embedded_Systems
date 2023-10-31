/*
 * arrayOfStudent.c
 *
 *  Created on: nov 1, 2023
 *      Author: Marina
 */

#include <stdio.h>

struct SStudent
{
	char name[50];
	int roll;
	float marks;
};

struct SStudent GetStudentInfo(int n);
void PrintStudentInfo(struct SStudent s);

int main()
{
	struct SStudent s[10];
	for(int i =1;i<=10;i++)
	{
		printf("for roll number %d\n",i);
		s[i-1]=GetStudentInfo(i);
	}
	for(int i =1;i<=10;i++)
	{
		PrintStudentInfo(s[i-1]);
	}
}

struct SStudent GetStudentInfo(int n)
{
	struct SStudent s;
	s.roll = n;
	printf("Enter name:");
	scanf("%s",&s.name);
	printf("Enter marks:");
	scanf("%f",&s.marks);
	return s;
}

void PrintStudentInfo(struct SStudent s)
{
	printf("Information for roll number %d:\nName: %s\nMarks: %.2f\n",s.roll,s.name,s.marks);
}