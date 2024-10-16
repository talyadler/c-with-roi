#pragma once

struct Emp {
	unsigned int id;
	char name[255];
	unsigned int age;
	char position[255];
	float salary;
};

// Prints the given employee to stdout 
void showEmp(Emp&);
