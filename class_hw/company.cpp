#include <iostream>
#include "validate.hpp"
#include "emp.hpp"
#include "company.hpp"

//1. Add Employee
void company::addEmp(){
	char more;
	do {
		Emp e;
		e.id = this->emplist.size()+1;
		validatechar("Type the full name of the employee: ", e.name, sizeof(e.name));
		e.age = validateint("Insert employee age: ");
		validatechar("What is the employee position? ", e.position, sizeof(e.position));
		e.salary = validatefloat("Insert employee salary: ");
		this->emplist.push_back(e);
		printf("Do you want to add more employees? ");
		std::cin >> more;
		printf("-------------------------\n");
	} while (more == 'y' || more =='Y');
}

// 2. Display All Employees
void company::showEmp() {
	for (size_t i = 0; i < this->emplist.size(); i++){
		printf("Employee %03ld\n"
		"\tID: \t\t%03d\n"
		"\tName: \t\t%s\n"
		"\tAge: \t\t%d\n"
		"\tPosition: \t%s\n"
		"\tSalary: \t%.1f\n"
		"-------------------------\n"
		,i+1, this->emplist[i].id, this->emplist[i].name, this->emplist[i].age, this->emplist[i].position, this->emplist[i].salary
	);
	}
}

// 3. Display Employee with Highest Salary
void company::highest(){
	Emp* max = &this->emplist[0];
	for(int i = 1; i < this->emplist.size(); ++i){
		if (this->emplist[i].salary > max->salary){
			max = &this->emplist[i];
		}
	}
	printf("The highest paid employee is:\n");
	max->Emp::showEmp();
}

// 4. Display Average Salary
void company::avg(){
		float avg = 0;
		for (int i = 0; i < this->emplist.size(); i++){
			avg = avg + this->emplist[i].salary;
		}
		avg = avg / this->emplist.size();
		printf("The avarge salary is: \n\t%.1f\n",avg);
}

// 5. Find Employee by ID
void company::findid(){
	if (this->emplist.empty()){
		printf("Please input employees first\n\n");
		return;
	}
	bool foundMatch = false;
	Emp* empid = nullptr;
	while (!foundMatch){
		unsigned int id = validateint("Please input desired ID: ");
		for(int i = 0; i < this->emplist.size() && !foundMatch; ++i){
			if (this->emplist[i].id == id) {
				empid = &this->emplist[i];
				foundMatch = true;
			}
		}
		if (!foundMatch){
			printf("No match\n");
			}
	}
	printf("The employee is:\n");
	empid->Emp::showEmp();
}
