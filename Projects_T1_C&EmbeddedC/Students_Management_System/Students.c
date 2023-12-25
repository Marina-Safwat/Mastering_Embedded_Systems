/*************************************************************************/
// Author        : Marina Safwat Barsoum Gerges
// Project       : Student_Information_Management_System_Project
// File          : Students.c
// Date          : Dec 22, 2023
// GitHub        : https://github.com/Marina-Safwat
/*************************************************************************/

#include "Students.h"

#define FileName "StudentsDB.txt"

//function to check if the ID unique or not
IDStatus IsIDUnique(struct Buf* Buff,uint32 GivenID)
{
	elementType* temp = Buff->tail;
	for(int i = 0;i < Buff->count;i++)
	{
		if(temp->ID == GivenID)
			return ID_Taken;
		if(temp == (Buff->base + (Buff->length * sizeof(elementType))))
			temp = Buff->base;
		else
			temp++;
	}
	return ID_Available;
}

//function to count students and to print database information
void CountStudents(struct Buf* Buff)
{
	printf("[INFO] The Total Number Of Students is %d\n",Buff->count);
	printf("[INFO] You Can Add Up To %d Students\n",Buff->length);
	printf("[INFO] You Can Add %d More Students\n",Buff->length - Buff->count);
	printf("=============================================\n");
}

//function to add new student manually
void AddManually(struct Buf* Buff)
{
	printf("Add The Student Information\n");
	printf("=============================================\n");

	//create new student struct
	elementType s ;

	//take IDs till entering a valid one
	do
	{
		//getting the ID of the student to add
		printf("Enter Unique ID : ");
		scanf("%d",&s.ID);
	}while((IsIDUnique(Buff,s.ID) == ID_Taken)&&(printf("===========This ID is already Taken==========\n=============================================\n")));


	//getting student first name to add
	printf("Enter Student First Name : ");
	scanf("%s",s.FirstName);

	//getting student last name to add
	printf("Enter Student Second Name : ");
	scanf("%s",s.LastName);

	//getting student GPA
	printf("Enter GPA : ");
	scanf("%f",&s.GPA);

	//to protect the program from wrong number of courses
	do
	{
		//getting the number of courses are enrolled in
		printf("Enter The Number Of Courses choosen (MAX = 10): ");
		scanf("%d",&s.CoursesNum);

		//getting courses IDs
		for(int i =0; i < s.CoursesNum;i++)
		{
			printf("Enter The ID Of Course %d : ",i+1);
			scanf("%d",&s.CoursesID[i]);
		}
	}while(!(s.CoursesNum <= 10 && s.CoursesNum >= 1)&&(printf("Please Enter Number From 1 To 10\n")));

	//add this student to the database
	Buffer_Status BS = FIFO_add_item(Buff,s);
	if(BS == FIFO_No_Error)
	{
		//add the student in the file

		//create file pointer
		FILE *fptr;

		// Open a file in read mode
		fptr = fopen(FileName, "a");

		//checking for file existance
		if(fptr == NULL) {
			printf("=============================================\n");
			printf("======There Is An Error In Opening File======\n");
			printf("=============================================\n");
		}

		//print student information in the file
		fprintf(fptr,"%d %s %s %.2f %d ",s.ID,s.FirstName,s.LastName,s.GPA,s.CoursesNum);
		for(int i =0; i < s.CoursesNum;i++)
		{
			fprintf(fptr,"%d ",s.CoursesID[i]);
		}
		fprintf(fptr,"\n");

		// Close the file
		fclose(fptr);

		//ending
		printf("=============================================\n");
		printf("==Student Information Is Added Successfully==\n");
		printf("=============================================\n");
	}
	else if(BS == FIFO_NULL)
	{
		printf("=============================================\n");
		printf("======There Is An Error In Accessing DB======\n");
		printf("=============================================\n");
	}
	else if(BS == FIFO_Full)
	{
		printf("=============================================\n");
		printf("============The Database Is Full=============\n");
		printf("=============================================\n");
	}

	//print the database information
	CountStudents(Buff);
}

//function to print the student information
void PrintStudentInfo(elementType* s)
{
	//print students information
	printf("=============================================\n");
	printf("=============Student Information=============\n");
	printf("=============================================\n");
	printf("The ID is %d\n",s->ID);
	printf("The First Name is %s\n",s->FirstName);
	printf("The Last Name is %s\n",s->LastName);
	printf("The GPA is %.2f\n",s->GPA);
	printf("The Number Of Courses Enrolled are %d\n",s->CoursesNum);
	for(int i =0; i <s->CoursesNum;i++)
	{
		printf("Course Number %d ID is %d\n",i+1,s->CoursesID[i]);
	}
	printf("=============================================\n");
}

//function to view the student information with the ID
IDStatus ViewOrUpdateByID(struct Buf* Buff,int n)
{
	//get the student id
	int id,i,NID;
	printf("Enter the ID of The Student :");
	scanf("%d",&id);

	//find the ID in the List
	elementType* temp = Buff->tail;
	for(int i = 0;i < Buff->count;i++)
	{
		if(temp->ID == id)
		{
			PrintStudentInfo(temp);

			//in Update mode
			if(n == 1)
			{
				//display the options list
				printf("Choose The Data Option You Wanna Update\n");
				printf("1: ID\n");
				printf("2: First Name\n");
				printf("3: Last Name\n");
				printf("4: GPA\n");
				printf("5: Courses\n");
				printf("6: Exit\n");

				//get user option
				int option;
				printf("Enter Your Option Number : ");
				scanf("%d",&option);
				printf("=============================================\n");

				//apply the task
				switch(option)
				{
				case 1 :
					//take IDs till entering a valid one
					do
					{
						//getting the ID of the student to add
						printf("Enter New Unique ID : ");
						scanf("%d",&NID);
					}while((IsIDUnique(Buff,NID) == ID_Taken)&&(printf("===========This ID is already Taken==========\n=============================================\n")));
					temp->ID = NID;
					printf("=============================================\n");
					break;
				case 2 :
					//getting student first name to add
					printf("Enter Student New First Name : ");
					scanf("%s",temp->FirstName);
					printf("=============================================\n");
					break;
				case 3 :
					//getting student last name to add
					printf("Enter Student New Second Name : ");
					scanf("%s",temp->LastName);
					printf("=============================================\n");
					break;
				case 4 :
					//getting student GPA
					printf("Enter New GPA : ");
					scanf("%f",&(temp->GPA));
					printf("=============================================\n");
					break;
				case 5 :
					//to protect the program from wrong number of courses
					do
					{
						//getting the number of courses are enrolled in
						printf("Enter The New Number Of Courses Chosen (MAX = 10): ");
						scanf("%d",&temp->CoursesNum);

						//getting courses IDs
						for(i =0; i < temp->CoursesNum;i++)
						{
							printf("Enter The ID Of Course %d : ",i+1);
							scanf("%d",&temp->CoursesID[i]);
						}
					}while(!(temp->CoursesNum <= 10 && temp->CoursesNum >= 1)&&(printf("Please Enter Number From 1 To 10\n")));

					//fill the rest of the array with -1
					for(; i < 10;i++)
					{
						temp->CoursesID[i] = -1;
					}
					printf("=============================================\n");
					break;
				case 6 :
					printf("=============================================\n");
					break;
					Default:
					printf("------Choose valid option------");
					break;
				}
			}
			return ID_Taken;
		}
		if(temp == (Buff->base + (Buff->length * sizeof(elementType))))
			temp = Buff->base;
		else
			temp++;
	}

	//not found
	printf("=============================================\n");
	printf("===========There Isn't ID Number %d===========\n",id);
	printf("=============================================\n");
	return ID_Available;
}

//function to view the student information with the first name
void ViewByFirstName(struct Buf* Buff)
{
	//get the student name
	char FN[50];
	printf("Enter the First Name of The Student :");
	scanf("%s",FN);

	//create flag to get if it is found
	char flag = 0;

	//find the Name in the List
	elementType* temp = Buff->tail;
	for(int i = 0;i < Buff->count;i++)
	{
		if(stricmp(temp->FirstName,FN) == 0)
		{
			PrintStudentInfo(temp);
			flag = 1;
		}
		if(temp == (Buff->base + (Buff->length * sizeof(elementType))))
			temp = Buff->base;
		else
			temp++;
	}

	//not found
	if(flag == 0)
	{
		printf("=============================================\n");
		printf("=====There Isn't Student With Name %s=====\n",FN);
		printf("=============================================\n");
	}
}

//function to view all students in the database
void ViewAll(struct Buf* Buff)
{
	//print the list
	elementType* temp = Buff->tail;
	for(int i = 0;i < Buff->count;i++)
	{
		PrintStudentInfo(temp);
		if(temp == (Buff->base + (Buff->length * sizeof(elementType))))
			temp = Buff->base;
		else
			temp++;
	}

	if(Buff->count)
	{
		//ending
		printf("=============================================\n");
		printf("=============The End Of The List=============\n");
		printf("=============================================\n");
	}
	else
	{
		//empty list
		printf("=============================================\n");
		printf("=================Empty List==================\n");
		printf("=============================================\n");
	}
}

//view students that enrolled in course by it's ID
void ViewCourseStudents(struct Buf* Buff)
{
	//get the student id
	int id;
	printf("Enter the ID of The Course :");
	scanf("%d",&id);

	//create flag to get if it is found
	char flag = 0;

	//print the list
	elementType* temp = Buff->tail;
	for(int i = 0;i < Buff->count;i++)
	{
		for(int j =0; j < temp->CoursesNum;j++)
		{
			if(temp->CoursesID[j] == id)
			{
				PrintStudentInfo(temp);
				flag = 1;
			}
		}
		if(temp == (Buff->base + (Buff->length * sizeof(elementType))))
			temp = Buff->base;
		else
			temp++;
	}

	//not found
	if(flag == 0)
	{
		printf("=============================================\n");
		printf("====There Aren't Students In Course ID %d====\n",id);
		printf("=============================================\n");
	}
}

//function to Add students from file
void AddFromFile(struct Buf* Buff)
{
	//create file pointer
	FILE *fptr;

	// Open a file in read mode
	fptr = fopen(FileName, "r");

	//checking for file existance
	if(fptr == NULL) {
		printf("=============================================\n");
		printf("======There Is An Error In Opening File======\n");
		printf("=============================================\n");
	}

	//loop in the file till the end
	while(!feof(fptr))
	{
		elementType s ;

		//store data from the file in the student struct
		fscanf(fptr,"%d ",&s.ID);
		fscanf(fptr,"%s ",s.FirstName);
		fscanf(fptr,"%s ",s.LastName);
		fscanf(fptr,"%f ",&s.GPA);
		fscanf(fptr,"%d ",&s.CoursesNum);
		for(int i =0; i < s.CoursesNum;i++)
		{
			fscanf(fptr,"%d ",&(s.CoursesID[i]));
		}

		//checking if the id is unique
		if(IsIDUnique(Buff,s.ID) == ID_Taken)
		{
			printf("[ERROR] ID Number %d Is Already Taken\n",s.ID);
			printf("=============================================\n");
		}
		else
		{
			//add this student to the database
			Buffer_Status BS = FIFO_add_item(Buff,s);
			if(BS == FIFO_No_Error)
			{
				//ending
				printf("=============================================\n");
				printf("==Student Information Is Added Successfully==\n");
				printf("=============================================\n");
			}
			else if(BS == FIFO_NULL)
			{
				printf("=============================================\n");
				printf("======There Is An Error In Accessing DB======\n");
				printf("=============================================\n");
			}
			else if(BS == FIFO_Full)
			{
				printf("=============================================\n");
				printf("============The Database Is Full=============\n");
				printf("=============================================\n");
			}
		}
	}

	//print the database information
	CountStudents(Buff);

	// Close the file
	fclose(fptr);
}

//function to delete student by ID from file and fifo
void DeleteByID(struct Buf* Buff)
{
	//create an element type variable
	elementType s;

	//get the id of the student you wanna delete
	int id;
	printf("Enter The ID Of The Student You Wanna Delete : ");
	scanf("%d",&id);

	//check if I found the ID
	if (IsIDUnique(Buff,id)) {
		//not found
		printf("=============================================\n");
		printf("===========There Isn't ID Number %d===========\n",id);
		printf("=============================================\n");
		return;
	}

	//remove it from the file
	//open file and create a temp file to move the data after deletion
	FILE *tfp,*fp;
	tfp = fopen("TempFile.txt","w");
	fp = fopen(FileName,"r");

	//checking for file existance
	if(fp == NULL) {
		printf("=============================================\n");
		printf("======There Is An Error In Opening File======\n");
		printf("=============================================\n");
	}

	//checking for file existance
	if(tfp == NULL) {
		printf("=============================================\n");
		printf("======There Is An Error In Opening File======\n");
		printf("=============================================\n");
	}

	//loop in the file till the end
	while (!feof(fp))
	{
		//scan data from the origin file
		fscanf(fp,"%d ",&s.ID);
		fscanf(fp,"%s ",s.FirstName);
		fscanf(fp,"%s ",s.LastName);
		fscanf(fp,"%f ",&s.GPA);
		fscanf(fp,"%d ",&s.CoursesNum);
		for(int i =0; i < s.CoursesNum;i++)
		{
			fscanf(fp,"%d ",&(s.CoursesID[i]));
		}

		//check if id found
		if(s.ID == id)
		{
			printf("=============================================\n");
			printf("===The Student Of ID %d Is Deleted From File==\n",id);
			printf("=============================================\n");
		}
		else
		{
			//print student information in the file
			fprintf(tfp,"%d %s %s %.2f %d ",s.ID,s.FirstName,s.LastName,s.GPA,s.CoursesNum);
			for(int i =0; i < s.CoursesNum;i++)
			{
				fprintf(tfp,"%d ",s.CoursesID[i]);
			}
			fprintf(tfp,"\n");
		}
	}

	//close files
	fclose(tfp);
	fclose(fp);

	//replace the file with temp
	remove(FileName);
	rename("TempFile.txt" , FileName);

	//remove it from the FIFO
	// checking if the buffer is exist
	if(FIFO_Is_Buffer_NULL(Buff) == FIFO_NULL)
	{
		printf("=============================================\n");
		printf("======There Is An Error In Accessing DB======\n");
		printf("=============================================\n");
	}

	//check if there is space for adding element
	if(FIFO_Is_Buffer_Empty(Buff) == FIFO_Empty)
	{
		printf("=============================================\n");
		printf("============The Database Is Empty============\n");
		printf("=============================================\n");
	}

	//find the ID in the List
	elementType* temp = Buff->tail;
	elementType* pre = Buff->tail;
	int flag = 0;
	for(int i = 0;i < Buff->count;i++)
	{
		if(flag)
		{
			//copy temp in pre
			*pre=*temp;
		}
		//if found id
		if(temp->ID == id)
		{
			flag = 1;
			printf("=============================================\n");
			printf("===The Student Of ID %d Is Deleted From FIFO==\n",id);
			printf("=============================================\n");
		}
		pre = temp;
		if(temp == (Buff->base + (Buff->length * sizeof(elementType))))
			temp = Buff->base;
		else
			temp++;
	}

	//reduce count
	Buff->count--;
	if(Buff->head == Buff->base)
		Buff->head = Buff->base+(Buff->length*sizeof(*(Buff->base)));
	else
		Buff->head--;
	//ending

}
