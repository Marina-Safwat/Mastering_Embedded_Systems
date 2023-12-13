// main to apply on Linked List Strudents DataBase
// by Marina Safwat
// 11/12/2023

#include "LLSDB.h"

struct SNode *GPFirstNode = NULL;

int main()
{
	while(1)
	{
		//display the options list
		printf("Choose One Of The Following Options\n");
		printf("1: Add Student\n");
		printf("2: Delete Student\n");
		printf("3: View Student\n");
		printf("4: View All Student\n");
		printf("5: Delete All Student\n");
		printf("6: Get Nth Student\n");
		printf("7: Get Length Of The List(Iteration)\n");
		printf("8: Get Length Of The List(Recursive)\n");
		printf("9: Get Nth From The End Student(Length)\n");
		printf("10: Get Nth From The End Student(Two Pointers)\n");
		printf("11: Get The Middle Student In The List\n");
		printf("12: Detect Loops In The List\n");
		printf("13: Reverse The List\n");
		printf("14: Exit The Program\n");
	
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
				Add();
				break;
			case 2 :
				Delete();
				break;
			case 3 :
				View();
				break;
			case 4 :
				ViewAll();
				break;
			case 5 :
				DeleteAll();
				break;
			case 6 :
				//get n from the user "number of student wanted"
				printf("Enter The Number That You Want To Get It's Student : ");
				scanf("%d",&n);
				getNth(n);
				break;
			case 7 :
				getLengthWithIterative();
				break;
			case 8 :
				n = getLengthWithRecursive(GPFirstNode);
				printf("The Length Of The List : %d\n",n);
				printf("=============================================\n");
				break;
			case 9 :
				getNthFromEndAL1();
				break;
			case 10 :
				getNthFromEndAL2();
				break;
			case 11 :
				getMiddle();
				break;
			case 12 :
				//printf("I'm in the case 12\n");
				detectLoops();
				break;
			case 13 :
				reverseList();
				break;
			case 14 :
				break;
			Default:
				printf("------Choose valid option------");
				break;
		}
		//if option = 14 break the loop to exit the program
		if(option == 14)
			break;
	}
	
	return 0;
}