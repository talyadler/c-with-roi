#include "emp.hpp"
#include <iostream>

// 2.1 Support function to display employee for other functions
void showEmp(Emp& emp) {
	printf("Employee\n"
		"\tID: \t\t%03d\n"
		"\tName: \t\t%s\n"
		"\tAge: \t\t%d\n"
		"\tPosition: \t%s\n"
		"\tSalary: \t%.1f\n"
		"-------------------------\n"
		,emp.id, emp.name, emp.age, emp.position, emp.salary
	);
}

