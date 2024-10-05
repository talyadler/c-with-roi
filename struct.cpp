#include <iostream>
#include "string.h"

struct Person {
	char name[255];
	char phone[11];
	char id[10];
};

//void fun(int num, char char1, float float1) -> void fun(StructOne s)

void printPerson(const Person& p) {
	printf("Person(name = %s, phone = %s, id = %s)\n", p.name, p.phone, p.id);
}

int main() {
	printf("sizeof(Person) = %ld\n", sizeof(Person));
	Person* pArr = new Person[2];
	Person* p2 = &pArr[1];
	strcpy(pArr[0].name, "Tal Adler");
	strcpy(pArr[0].phone, "0535304647");
	strcpy(pArr[0].id, "000000000");
	strcpy(p2->name, "Roi Tiefenbrunn");
	strcpy(p2->phone, "0547168459");
	strcpy(p2->id, "123456789");
	printPerson(pArr[0]);
	printPerson(*p2);
	delete[] pArr;
}
