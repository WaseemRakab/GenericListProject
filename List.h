#ifndef _List
#define _List
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
typedef enum Type { Char, Int, Float, Double, Long, String, Object } TypeOfList;
typedef struct List List;
struct List
{
	void* List;
	TypeOfList Type;
	size_t sizeOfListVal;
	size_t Capacity;
	size_t Count;
};

List* CreateNewList(TypeOfList Type, unsigned long long Size, size_t Capacity);
static bool AddValue(List** list, void* value);
static void* GetValue(List* list, size_t Index);
char* ToString(List* list);

void* GetObject(List* list, size_t Index);
char GetChar(List* list, size_t Index);
int GetInt(List* list, size_t Index);
float GetFloat(List* list, size_t Index);
double GetDouble(List* list, size_t Index);
long long GetLong(List* list, size_t Index);
char* GetString(List* list, size_t Index);

bool AddObject(List** list, void* value);
bool AddChar(List** list, char value);
bool AddInt(List** list, int value);
bool AddFloat(List** list, float value);
bool AddDouble(List** list, double value);
bool AddLong(List** list, long long value);
bool AddString(List** list, char* value);
#endif //_List