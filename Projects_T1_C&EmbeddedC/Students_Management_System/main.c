/*************************************************************************/
// Author        : Marina Safwat Barsoum Gerges
// Project       : Student_Information_Management_System_Project
// File          : main.c
// Date          : Dec 22, 2023
// GitHub        : https://github.com/Marina-Safwat
/*************************************************************************/

#include "Students.h"
#include "FIFO.h"

//create queue and struct for it's information
elementType buffer[Buffer_Length];

int main()
{
	FIFO_Buffer_t StudentsDBInfo;
	//set queue info
	FIFO_init(&StudentsDBInfo,buffer,Buffer_Length);

	//start the program
	while(1)
	{
		//display the options list
		printf("Choose One Of The Following Options\n");
		printf("1: Add Student(Text File)\n");
		printf("2: Add Student(Manually)\n");
		printf("3: View Student(By ID)\n");
		printf("4: View Student(By First Name)\n");
		printf("5: View All Students Enrolled In A Course\n");
		printf("6: View All Students\n");
		printf("7: Delete Student(By ID)\n");
		printf("8: Update Student(By ID)\n");
		printf("9: Get Total Number Of Students\n");
		printf("10: Exit The Program\n");

		//get user option
		int option;
		printf("Enter Your Option Number : ");
		scanf("%d",&option);
		printf("=============================================\n");

		//important declaration
		int n;

		//excute the option based on the number
		switch(option)
		{
			case 1 :
				AddFromFile(&StudentsDBInfo);
				break;
			case 2 :
				AddManually(&StudentsDBInfo);
				break;
			case 3 :
				ViewOrUpdateByID(&StudentsDBInfo,0);
				break;
			case 4 :
				ViewByFirstName(&StudentsDBInfo);
				break;
			case 5 :
				ViewCourseStudents(&StudentsDBInfo);
				break;
			case 6 :
				ViewAll(&StudentsDBInfo);
				break;
			case 7 :
				DeleteByID(&StudentsDBInfo);
				break;
			case 8 :
				ViewOrUpdateByID(&StudentsDBInfo,1);
				break;
			case 9 :
				CountStudents(&StudentsDBInfo);
				break;
			case 10 :
				break;
			Default:
				printf("------Choose valid option------");
				break;
		}
		//if option = 14 break the loop to exit the program
		if(option == 10)
		{
			printf("============the program terminated===========\n");
			printf("=============================================\n");
			break;
		}
	}

	return 0;
}
