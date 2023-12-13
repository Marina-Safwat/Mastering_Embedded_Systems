// by Marina Safwat
// 11/12/2023

#include "LLSDB.h"

//function to add new student
void Add()
{
	//creating new node and pointer to it
	struct SNode* NewNode = (struct SNode*) malloc(sizeof(struct SNode));
	
	//getting the ID of the student to add
	printf("Enter The ID : ");
	scanf("%d",&NewNode->Student.id);
	
	//getting student name to add
	printf("Enter Student Name : ");
	scanf("%s",NewNode->Student.name);
	
	//getting student height
	float HEIGHT;
	printf("Enter Height : ");
	scanf("%f",&NewNode->Student.height);
	
	//put the next node to NULL
	NewNode->PNextNode = NULL;
	
	//put the node in the list
	if(GPFirstNode == NULL) // if the list is empty 
		GPFirstNode = NewNode; // put it in the first place
	else //the list is not empty
	{
		//create temp pointer to loop with
		struct SNode* PCurrNode = GPFirstNode;
		
		//loop till the last node "finding NULL"
		while(PCurrNode->PNextNode)
			PCurrNode = PCurrNode->PNextNode;
		
		//link our new node to the list
		PCurrNode->PNextNode = NewNode;
	}
	
	//ending
	printf("================Insertion Done===============\n");
	printf("=============================================\n");
}

//function to delete specific student by the ID
int Delete()
{
	//check if the list is empty
	if(GPFirstNode == NULL)
	{
		printf("=================Empty List==================\n");
		printf("=============================================\n");
		return 0;
	}
	
	//getting the student ID to delete
	int ID;
	printf("Enter The Student ID To Be Deleted : ");
	scanf("%d",&ID);
	
	//create temp pointers to hold current and previous nodes
	struct SNode* PCurrNode = GPFirstNode;
	struct SNode* PPreNode = GPFirstNode;
		
	//loop till the last node or finding ID
	while(PCurrNode)
	{
		//check if it is the node to be deleted
		if(PCurrNode->Student.id == ID)
		{
			//checking if it is the first element in the list 
			if(PCurrNode == GPFirstNode)
				GPFirstNode = PCurrNode->PNextNode;
			else //in the middle or end of the list
				PPreNode->PNextNode = PCurrNode->PNextNode;
			free(PCurrNode);//to delete the node 
			
			//ending
			printf("================Deletion Done================\n");
			printf("=============================================\n");
			return 1;
		}
		
		//next step
		PPreNode = PCurrNode;
		PCurrNode = PCurrNode->PNextNode;
	}
	
	//if it is NOT FOUND
	printf("==================Wrong ID===================\n");
	printf("=============================================\n");
	return 0;
}

//function to view specific student by the ID
int View()
{
	//check if the list is empty
	if(GPFirstNode == NULL)
	{
		printf("=================Empty List==================\n");
		printf("=============================================\n");
		return 0;
	}
	
	//getting the student ID to viewed
	int ID;
	printf("Enter The Student ID To Be Viewed : ");
	scanf("%d",&ID);
	
	//create temp pointers to hold current and previous nodes
	struct SNode* PCurrNode = GPFirstNode;
		
	//loop till the last node or finding ID
	while(PCurrNode)
	{
		//check if it is the node to be deleted
		if(PCurrNode->Student.id == ID)
		{
			//print the node information
			printf("Student ID : %d\n",PCurrNode->Student.id);
			printf("Student Name : ");
			puts(PCurrNode->Student.name);
			printf("Student Height : %.2f\n",PCurrNode->Student.height);
			printf("=============================================\n");
			
			//ending
			printf("====================found====================\n");
			printf("=============================================\n");
			return 1;
		}
		
		//next step
		PCurrNode = PCurrNode->PNextNode;
	}
	
	//if it is NOT FOUND
	printf("==================Wrong ID===================\n");
	printf("=============================================\n");
	return 0;
}

//function to print all students in the list
int ViewAll()
{
	int count = 1; //counter to display the record number
	
	//create temp pointer to loop with
	struct SNode* PCurrNode = GPFirstNode;
	
	//check if the list is empty
	if(GPFirstNode == NULL)
	{
		printf("=================Empty List==================\n");
		printf("=============================================\n");
		return 0;
	}
		
	//loop till the last node "finding NULL"
	while(PCurrNode)
	{
		//print the node information
		printf("Record Number : %d\n",count);
		printf("Student ID : %d\n",PCurrNode->Student.id);
		printf("Student Name : ");
		puts(PCurrNode->Student.name);
		printf("Student Height : %.2f\n",PCurrNode->Student.height);
		printf("=============================================\n");
		
		//go to the next node
		PCurrNode = PCurrNode->PNextNode;
		count++;
	}
	
	//ending
	printf("===============End Of The List===============\n");
	printf("=============================================\n");
	return 1;
}

//function to delete all students from the list
int DeleteAll()
{
	//check if the list is empty
	if(GPFirstNode == NULL)
	{
		printf("=================Empty List==================\n");
		printf("=============================================\n");
		return 0;
	}
	
	//create temp pointer to loop with
	struct SNode* PCurrNode = GPFirstNode;
	
	//loop over the list to delete it 
	while(PCurrNode)
	{
		struct SNode* temp = PCurrNode;
		PCurrNode = PCurrNode->PNextNode;
		free(temp);
	}
	
	GPFirstNode = NULL;
	
	//ending
	printf("==============Deletion All Done==============\n");
	printf("=============================================\n");
	return 1;
}

//function to get the student number n in the list
int getNth(int n)
{
	//check if the list is empty
	if(GPFirstNode == NULL)
	{
		printf("=================Empty List==================\n");
		printf("=============================================\n");
		return 0;
	}
	
	//loop in the list to get the student
	int count = 1 ;
	struct SNode* PCurrNode = GPFirstNode;

	while(PCurrNode)
	{
		if(count == n)
		{
			//print the node information
			printf("The Student Number %d In The List is :\n",count);
			printf("Student ID : %d\n",PCurrNode->Student.id);
			printf("Student Name : ");
			puts(PCurrNode->Student.name);
			printf("Student Height : %.2f\n",PCurrNode->Student.height);
			printf("=============================================\n");
			return 1;
		}
		count++;
		PCurrNode = PCurrNode->PNextNode;
	}
	printf("======there isn't student in that number=====\n");
	printf("=============================================\n");
	return 0;
}

//function to get the length of the list by iterative method
void getLengthWithIterative()
{
	//loop in the list to it's length
	int count = 0 ;
	struct SNode* PCurrNode = GPFirstNode;

	while(PCurrNode)
	{
		count++;
		PCurrNode = PCurrNode->PNextNode;
	}
	
	//printing the length of the list
	printf("The Length Of The List : %d\n",count);
	
	//ending
	printf("=============================================\n");
}

//function to get the length of the list by iterative method
int getLengthWithRecursive(struct SNode* PCurrNode)
{
	if(PCurrNode == NULL)
		return 0;
	
	return 1 + getLengthWithRecursive(PCurrNode->PNextNode);
}

//function to get the student number n from the end of the list
int getNthFromEndAL1()
{
	//check if the list is empty
	if(GPFirstNode == NULL)
	{
		printf("=================Empty List==================\n");
		printf("=============================================\n");
		return 0;
	}
	
	//get n from the user "number of student wanted"
	int n;
	printf("Enter The Number That You Want To Get It's Student From The End : ");
	scanf("%d",&n);
	
	//get the n from the first 
	int x = getLengthWithRecursive(GPFirstNode);
	x = x - n + 1;
	
	//get it's information
	getNth(x);
	
	//ending
	printf("=============================================\n");
	return 1;
}

//function to get the student number n from the end of the list with 2 pointers
int getNthFromEndAL2()
{
	//check if the list is empty
	if(GPFirstNode == NULL)
	{
		printf("=================Empty List==================\n");
		printf("=============================================\n");
		return 0;
	}
	
	//get n from the user "number of student wanted"
	int n;
	printf("Enter The Number That You Want To Get It's Student From The End : ");
	scanf("%d",&n);
	
	//create two pointers
	int count = 0;
	struct SNode* PMainNode = GPFirstNode;
	struct SNode* PRefNode = GPFirstNode;
	
	//loop till the last node or finding ID
	while(PRefNode)
	{
		if(count < n)
		{
			PRefNode = PRefNode->PNextNode;
			count++;
		}
		else if(count == n)
		{
			PMainNode = PMainNode->PNextNode;
			PRefNode = PRefNode->PNextNode;
		}
	}
	
	//print the node information
	printf("The Student Number %d In The List from the end is :\n",count);
	printf("Student ID : %d\n",PMainNode->Student.id);
	printf("Student Name : ");
	puts(PMainNode->Student.name);
	printf("Student Height : %.2f\n",PMainNode->Student.height);
	printf("=============================================\n");
	return 1;
}

//function to get the middle student in the list
int getMiddle()
{
	//check if the list is empty
	if(GPFirstNode == NULL)
	{
		printf("=================Empty List==================\n");
		printf("=============================================\n");
		return 0;
	}
	
	//create two pointers
	int count = 1;
	struct SNode* PSlow = GPFirstNode;
	struct SNode* PFast = GPFirstNode;
	
	//loop till the last node
	while(PFast->PNextNode)
	{
		//slow take a step & fast take 2 steps
		PSlow = PSlow->PNextNode;
		PFast = PFast->PNextNode->PNextNode;
		count++;  
	}
	
	//print the node information
	printf("The Middle Student In The List is Number %d\n",count);
	printf("Student ID : %d\n",PSlow->Student.id);
	printf("Student Name : ");
	puts(PSlow->Student.name);
	printf("Student Height : %.2f\n",PSlow->Student.height);
	printf("=============================================\n");
	return 1;
}

//function to detect if the is a loop in my list
int detectLoops()
{
	//printf("I'm in the detect loop\n");
	//check if the list is empty
	if(GPFirstNode == NULL)
	{
		printf("=================Empty List==================\n");
		printf("=============================================\n");
		return 0;
	}
	
	//create two pointers
	struct SNode* PSlow = GPFirstNode;
	struct SNode* PFast = GPFirstNode;
	
	//loop till the last node or finding the loop
	while(PFast->PNextNode)
	{
		//slow take a step & fast take 2 steps
		PSlow = PSlow->PNextNode;
		PFast = PFast->PNextNode->PNextNode;
		
		//if fast = slow it is a loop
		if(PSlow == PFast)
		{
			printf("There is a loop\n");
			printf("=============================================\n");
			return 1;
		}
	}
	
	//you reach the end of the list so there isn't a loop
	printf("There isn't a loop\n");
	printf("=============================================\n");
	return 0;
}

//function to reverse the list
int reverseList()
{
	//check if the list is empty
	if(GPFirstNode == NULL)
	{
		printf("=================Empty List==================\n");
		printf("=============================================\n");
		return 0;
	}
	
	//create three pointers
	struct SNode* PPrevNode = NULL;
	struct SNode* PcurrNode = GPFirstNode;
	struct SNode* PNextNode = GPFirstNode;
	
	//loop to reverse the list
	while(PcurrNode)
	{
		PNextNode = PcurrNode->PNextNode;
		PcurrNode->PNextNode = PPrevNode;
		PPrevNode = PcurrNode;
		PcurrNode = PNextNode;
	}
	GPFirstNode = PPrevNode;
	
	//view the list with the current order
	ViewAll();
	return 1;
}