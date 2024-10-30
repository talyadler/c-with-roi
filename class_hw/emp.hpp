#pragma once

class Emp {
public:
	// fields - these members detail the 'struct' part of the object
	unsigned int id;
	char name[255];
	unsigned int age;
	char position[255];
	float salary;

	// methods - these members detail 'functions' that use the 'struct' part:
	//
	// we removed the struct parameter, 
	// instead an implicit argument of type pointer-to-the-struct-part, named 'this', is given by default
	void showEmp();
};

// Prints the given employee to stdout 
// void showEmp(Emp& emp);
