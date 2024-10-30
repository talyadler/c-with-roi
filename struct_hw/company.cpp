#include <iostream>
#include "validate.hpp"
#include "emp.hpp"
#include "company.hpp"

//1. Add Employee
void addEmp(std::vector<Emp>& emplist){
	char more;
	do {
		Emp e;
		e.id = emplist.size()+1;
		validatechar("Type the full name of the employee: ", e.name, sizeof(e.name));
		e.age = validateint("Insert employee age: ");
		validatechar("What is the employee position? ", e.position, sizeof(e.position));
		e.salary = validatefloat("Insert employee salary: ");
		emplist.push_back(e);
		printf("Do you want to add more employees? ");
		std::cin >> more;
		printf("-------------------------\n");
	} while (more == 'y' || more =='Y');
}

// 2. Display All Employees
void showEmp(std::vector<Emp>& emplist) {
	for (size_t i = 0; i < emplist.size(); i++){
		printf("Employee %03ld\n"
		"\tID: \t\t%03d\n"
		"\tName: \t\t%s\n"
		"\tAge: \t\t%d\n"
		"\tPosition: \t%s\n"
		"\tSalary: \t%.1f\n"
		"-------------------------\n"
		,i+1, emplist[i].id, emplist[i].name, emplist[i].age, emplist[i].position, emplist[i].salary
	);
	}
}

// 3. Display Employee with Highest Salary
void highest(std::vector<Emp>& emplist){
	Emp* max = &emplist[0];
	for(int i = 1; i < emplist.size(); ++i){
		if (emplist[i].salary > max->salary){
			max = &emplist[i];
		}
	}
	printf("The highest paid employee is:\n");
	showEmp(*max);
}

// 4. Display Average Salary
void avg(std::vector<Emp>& emplist){
		float avg = 0;
		for (int i = 0; i < emplist.size(); i++){
			avg = avg + emplist[i].salary;
		}
		avg = avg / emplist.size();
		printf("The avarge salary is: \n\t%.1f\n",avg);
}

// 5. Find Employee by ID
void findid(std::vector<Emp>& emplist){
	if (emplist.size()==0){
		printf("Please input employees first\n\n");
		return;
	}
	bool foundMatch = false;
	Emp* empid = nullptr;
	while (!foundMatch){
		unsigned int id = validateint("Please input desired ID: ");
		for(int i = 0; i < emplist.size(); ++i){
			if (emplist[i].id == id){
				empid = &emplist[i];
				foundMatch = true;
				break;
			}
		}
		if (!foundMatch){
			printf("No match\n");
			}
	}
	printf("The employee is:\n");
	showEmp(*empid);
}

