#include "List.h"
#pragma warning(disable:6001)

List* CreateNewList(TypeOfList Type, unsigned long long Size, size_t Capacity)
{
	List* list = malloc(sizeof(List));
	if (list != NULL)
	{
		list->List = NULL;
		list->Capacity = Capacity;
		list->Type = Type;
		list->Count = 0;
		switch (Type)
		{
		case Char:
		case Int:
		case Float:
		case Double:
		case Long:
		case String:
			list->List = malloc((list->sizeOfListVal = sizeof(void*)) * Capacity);
			break;
		case Object:
			list->List = malloc((list->sizeOfListVal = Size) * Capacity);
		}
		return list;
	}
	return NULL;
}

static bool AddValue(List** list, void* value)
{
	if ((*list)->Count >= (*list)->Capacity)
	{
		void* temp = (*list)->List;
		(*list)->Capacity += 5;
		temp = realloc((*list)->List, (*list)->sizeOfListVal * (*list)->Capacity);
		if (temp != NULL)
			(*list)->List = temp;
	}
	void** data = (void**)(*list)->List;
	void* newAddr = malloc(sizeof(void*));
	if (newAddr != NULL)
	{
		memcpy(newAddr, value, sizeof(void*));
		data[(*list)->Count++] = newAddr;
		return true;
	}
	return false;
}

static void* GetValue(List* list, size_t Index)
{
	if (Index < list->Count)
	{
		void** data = (void**)list->List;
		return data[Index];
	}
	return NULL;
}

void* GetObject(List* list, size_t Index)
{
	void* val = GetValue(list, Index);
	if (val != NULL)
		return *((void**)(val));
	return NULL;
}

char GetChar(List* list, size_t Index)
{
	void* val = GetValue(list, Index);
	if (val != NULL)
		return *((char*)(val));
	return -1;
}

int GetInt(List* list, size_t Index)
{
	void* val = GetValue(list, Index);
	if (val != NULL)
		return *((int*)(val));
	return -1;
}

float GetFloat(List* list, size_t Index)
{
	void* val = GetValue(list, Index);
	if (val != NULL)
		return *((float*)(val));
	return -1;
}

double GetDouble(List* list, size_t Index)
{
	void* val = GetValue(list, Index);
	if (val != NULL)
		return *((double*)(val));
	return -1;
}

long long GetLong(List* list, size_t Index)
{
	void* val = GetValue(list, Index);
	if (val != NULL)
		return *((long long*)(val));
	return -1;
}

char* GetString(List* list, size_t Index)
{
	void* val = GetValue(list, Index);
	if (val != NULL)
		return *((char**)(val));
	return "";
}

char* ToString(List* list)
{
	if (list->List == NULL || list->Count < 1)
		return NULL;
	if (list->Type == Object) return "Object";
	size_t maxCap = (list->Count * 2) + 1;
	char* listRepresent = calloc(maxCap, sizeof(char)), * temp = NULL;
	size_t stringLength = 0;
	char buf[200] = { 0 };
	for (size_t i = 0; i < list->Count; ++i)
	{
		switch (list->Type)
		{
		case Char:
			sprintf(buf, "%c ", GetChar(list, i));
			break;
		case Int:
			sprintf(buf, "%d ", GetInt(list, i));
			break;
		case Float:
			sprintf(buf, "%.3f ", GetFloat(list, i));
			break;
		case Double:
			sprintf(buf, "%.3lf ", GetDouble(list, i));
			break;
		case Long:
			sprintf(buf, "%lld ", GetLong(list, i));
			break;
		case String:
			sprintf(buf, "%s\n", GetString(list, i));
			break;
		};
		size_t bufferLength = strlen(buf) + 1;
		if ((stringLength + bufferLength) >= maxCap)
		{
			maxCap = (stringLength + bufferLength) * 2;
			temp = realloc(listRepresent, sizeof(char) * maxCap);
			if (temp != NULL)
			{
				strcpy(temp, listRepresent);
				listRepresent = temp;
			}
		}
		if (listRepresent != NULL)
		{
			strcat(listRepresent, buf);
			stringLength = strlen(listRepresent) + 1;
		}
	}
	return listRepresent;
}

bool AddObject(List** list, void* value) 
{
	if ((*list)->Type != Object)return false;
	void* data = &value;
	return AddValue(list, data);
}

bool AddChar(List** list, char value)
{
	if ((*list)->Type != Char)return false;
	void* data = &value;
	return AddValue(list, data);
}

bool AddInt(List** list, int value)
{
	if ((*list)->Type != Int)return false;
	void* data = &value;
	return AddValue(list, data);
}

bool AddFloat(List** list, float value)
{
	if ((*list)->Type != Float)return false;
	void* data = &value;
	return AddValue(list, data);
}

bool AddDouble(List** list, double value)
{
	if ((*list)->Type != Double)return false;
	void* data = &value;
	return AddValue(list, data);
}

bool AddLong(List** list, long long value)
{
	if ((*list)->Type != Long)return false;
	void* data = &value;
	return AddValue(list, data);
}

bool AddString(List** list, char* value)
{
	if ((*list)->Type != String)return false;
	void* data = &value;
	return AddValue(list, data);
}