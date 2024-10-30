#include <iostream>
#include "emp.hpp"

// Support function to display employee for other functions
void Emp::showEmp(/*Emp* this*/) {
	printf("Employee\n"
		"\tID: \t\t%03d\n"
		"\tName: \t\t%s\n"
		"\tAge: \t\t%d\n"
		"\tPosition: \t%s\n"
		"\tSalary: \t%.1f\n"
		"-------------------------\n"
		,this->id, this->name, this->age, this->position, this->salary
	);
}

