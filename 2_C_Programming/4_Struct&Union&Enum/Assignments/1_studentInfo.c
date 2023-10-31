/*
 * studentInfo.c
 *
 *  Created on: oct 30, 2023
 *      Author: Marina
 */

#include <stdio.h>

struct SStudent
{
	char name[50];
	int roll;
	float marks;
};

struct SStudent GetStudentInfo();
void PrintStudentInfo(struct SStudent s);

int main()
{
	struct SStudent s;
	s = GetStudentInfo();
	PrintStudentInfo(s);
}

struct SStudent GetStudentInfo()
{
	struct SStudent s;
	printf("Enter name:");
	scanf("%s",&s.name);
	printf("Enter roll number:");
	scanf("%d",&s.roll);
	printf("Enter marks:");
	scanf("%f",&s.marks);
	return s;
}

void PrintStudentInfo(struct SStudent s)
{
	printf("Name: %s\nRoll: %d\nMarks: %.2f\n",s.name,s.roll,s.marks);
}