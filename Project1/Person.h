#ifndef _Person
#define _Person
#include "List.h"

typedef struct Person Person;
struct Person 
{
	long Id;
	char* Name;
	int Age;
	char Gender;
	char* Country;
	List* Grades;
};
#endif