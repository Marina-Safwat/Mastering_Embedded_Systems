// by Marina Safwat
// 11/12/2023

#ifndef LLSDB_H_
#define LLSDB_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct SData{
	uint32_t id;
	uint8_t name[40];
	float height;
};

struct SNode{
	struct SData Student;
	struct SNode *PNextNode;
};

extern struct SNode *GPFirstNode;

void Add(); //1
int Delete(); //2
int View(); //3
int ViewAll(); //4
int DeleteAll(); //5
int getNth(int n); //6
void getLengthWithIterative(); //7
int getLengthWithRecursive(struct SNode* PCurrNode); //8
int getNthFromEndAL1(); //9
int getNthFromEndAL2(); //10
int getMiddle(); //11
int detectLoops(); //12
int reverseList(); //13

#endif