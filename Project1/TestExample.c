#include "List.h"
#include "Person.h"

void ListAPITest()
{
	List* persons = CreateNewList(Object, sizeof(Person), 3);
	Person* person1 = malloc(sizeof(Person));
	if (person1 != NULL)
	{
		person1->Id = 21645174, person1->Name = "Test2", person1->Age = 23, person1->Gender = 'm', person1->Country = "IL", person1->Grades = CreateNewList(Int, sizeof(int), 3);
		AddInt(&person1->Grades, 95);
		AddInt(&person1->Grades, 79);
		AddInt(&person1->Grades, 86);
		AddInt(&person1->Grades, 99);
	}
	Person* person2 = malloc(sizeof(Person));
	if (person2 != NULL)
	{
		person2->Id = 251414, person2->Name = "Test4", person2->Age = 16, person2->Gender = 'f', person2->Country = "Ru", person2->Grades = CreateNewList(Int, sizeof(int), 5);
		AddInt(&person2->Grades, 100);
		AddInt(&person2->Grades, 90);
		AddInt(&person2->Grades, 80);
		AddInt(&person2->Grades, 70);
		AddInt(&person2->Grades, 75);
		AddInt(&person2->Grades, 80);
	}
	Person* person3 = malloc(sizeof(Person));
	if (person3 != NULL)
	{
		person3->Id = 5747474, person3->Name = "Yt", person3->Age = 24, person3->Gender = 'f', person3->Country = "MK", person3->Grades = CreateNewList(Int, sizeof(int), 7);
		AddInt(&person3->Grades, 90);
		AddInt(&person3->Grades, 94);
		AddInt(&person3->Grades, 100);
		AddInt(&person3->Grades, 85);
		AddInt(&person3->Grades, 88);
		AddInt(&person3->Grades, 77);
	}
	AddObject(&persons, person1);
	AddObject(&persons, person2);
	AddObject(&persons, person3);
	Person* person1FromList = ((Person*)(GetObject(persons, 0)));
	Person* person2FromList = ((Person*)(GetObject(persons, 1)));
	Person* person3FromList = ((Person*)(GetObject(persons, 2)));

	AddInt(&person1FromList->Grades, 47);
	printf("%s\n", ToString(person1FromList->Grades));
	printf("%s\n", ToString(person2FromList->Grades));
	printf("%s\n", ToString(person3FromList->Grades));
	List* myStringList = CreateNewList(String, sizeof(char*), 11);
	if (myStringList->List != NULL)
	{
		int val = 10;
		for (size_t i = 0; i < myStringList->Capacity; i++)
		{
			AddString(&myStringList, "Hello World" + i);
		}
		printf("%s", ToString(myStringList));
	}
	List* myLongList = CreateNewList(Long, sizeof(long long), 25);
	if (myLongList->List != NULL)
	{
		int val = 10;
		for (size_t i = 0; i < myLongList->Capacity; i++)
		{
			AddLong(&myLongList, (i *2));
		}
		AddLong(&myLongList, 90 * 2);
		AddLong(&myLongList, 90 * 3);
		printf("%s", ToString(myLongList));
	}
	List* listOfLists = CreateNewList(Object, sizeof(List), 1);
	AddObject(&listOfLists, CreateNewList(Int, sizeof(int), 2));
	AddObject(&listOfLists, CreateNewList(String, sizeof(char*), 4));
	AddObject(&listOfLists, CreateNewList(Double, sizeof(double), 5));

	List* listInd0 = ((List*)(GetObject(listOfLists, 0)));
	List* listInd1 = ((List*)(GetObject(listOfLists, 1)));
	List* listInd2 = ((List*)(GetObject(listOfLists, 2)));

	AddInt(&listInd0, 25);
	AddInt(&listInd0, 10);
	AddInt(&listInd0, 254);

	AddString(&listInd1, "Hello World");
	AddString(&listInd1, " Cool");
	AddString(&listInd1, " nice");
	AddString(&listInd1, "Api");

	AddDouble(&listInd2, 584.695);
	AddDouble(&listInd2, 5947.651);
	AddDouble(&listInd2, 9056.54);
	AddDouble(&listInd2, 125.25);
	AddDouble(&listInd2, 9154.36);

	printf("\n%s\n", ToString(listInd0));
	printf("\n%s\n", ToString(listInd1));
	printf("\n%s\n", ToString(listInd2));
}

int main()
{
	ListAPITest();
	return 0;
}