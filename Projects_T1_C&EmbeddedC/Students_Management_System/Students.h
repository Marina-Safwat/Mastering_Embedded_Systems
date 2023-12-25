/*************************************************************************/
// Author        : Marina Safwat Barsoum Gerges
// Project       : Student_Information_Management_System_Project
// File          : Students.h
// Date          : Dec 22, 2023
// GitHub        : https://github.com/Marina-Safwat
/*************************************************************************/

#ifndef STUDENTS_H_
#define STUDENTS_H_

#include "FIFO.h"
#include "string.h"

#define Buffer_Length 50
#define elementType struct Student

typedef enum{
	ID_Taken,
	ID_Available
}IDStatus;

struct Student{
	uint8 FirstName[50];
	uint8 LastName[50];
	uint32 ID;
	float32 GPA;
	uint32 CoursesID[10];
	uint32 CoursesNum;
};

void AddManually(struct Buf* Buff); //1
void AddFromFile(struct Buf* Buff); //2
IDStatus ViewOrUpdateByID(struct Buf* Buff,int n); //3 & //9
void ViewByFirstName(struct Buf* Buff); //4
void ViewCourseStudents(struct Buf* Buff); //5
void ViewAll(struct Buf* Buff); //6
void DeleteByID(struct Buf* Buff); //7
void CountStudents(struct Buf* Buff); //9

IDStatus IsIDUnique(struct Buf* Buff,uint32 GivenID);
void PrintStudentInfo(elementType* s);


#endif /* STUDENTS_H_ */
