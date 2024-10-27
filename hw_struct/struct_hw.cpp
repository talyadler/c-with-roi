#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstring>
#include "emp.cpp"
#include "validate.cpp"

/*
 *Objective:
Write a C++ program that uses a struct to manage a small company's employee
information. The program should allow the user to input employee details, display them,
and calculate additional statistics.
Task:
Create a struct called Employee with the following attributes:
-------------------------------------------
id: A unique integer for the employee's ID.
name: A string for the employee's name.
age: An integer for the employee's age.
position: A string for the employee's job position.
salary: A float for the employee's monthly salary.
-------------------------------------------
Create a menu that allows the user to:
Add a new employee to a list (array or vector).
Display all employees.
Display the employee with the highest salary.
Display the average salary of all employees.
Find and display an employee's details using their ID.
Exit the program.
Requirements:
Add Employee: The user should be able to add new employees until they choose to stop.
Prompt the user for all necessary details.
Store each employee's information in an array or a vector of Employee structs.
Display All Employees: Display all employees' information, showing their ID, name, age,
position, and salary.
Find Highest Salary: Display the name and salary of the employee with the highest salary.
Average Salary: Calculate and display the average salary of all employees.
Find Employee by ID: Allow the user to input an employee ID and display the details of
the corresponding employee. If the employee doesn't exist, display an appropriate
message.
Input Validation: Ensure that age is non-negative, salary is positive, and employee IDs are
unique.
Example Output:
*/

int menu(){
	int choice;
	printf("##########################\n"
		"Welcome to employee menu:\n"
		"#########################\n"
		"Please choose a number to start:\n"
		"\t1.Add an employee.\n"
		"\t2.Display all employees.\n"
		"\t3.Display the employee with the highest salary.\n"
		"\t4.Display the average salary of all employees.\n"
		"\t5.Find and display an employee's details using their ID.\n"
		"\t6.Exit the program.\n"
		"-------------------------\n"
		"Your choice: "
	);
	while (!(std::cin >> choice)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Your choice: ";
	}
	printf("-------------------------\n");
	return choice;
}

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
	Emp* empid;
	while (!foundMatch){
		unsigned int id = validateint("Please input desired ID: ");
		for(int i = 0; i < emplist.size(); ++i){
			if (emplist[i].id == id){
				empid = &emplist[i];
				foundMatch = true;
				break;
			}
		}
		printf("No match\n");
	}
	printf("The employee is:\n");
	showEmp(*empid);
}

// 6. Exit
void bye(std::vector<Emp>& empList) {
	printf("Bye\n");
	exit(0);
}

int main(){
	void (*menuArr[])(std::vector<Emp>&) = {&addEmp, &showEmp, &highest, &avg, &findid, &bye};
	std::vector<Emp> emplist;
	do {
		int choice = menu();
		if (1 <= choice && choice <= 6) {
			menuArr[choice - 1](emplist);
		} else {
			printf("you have chosen an invalid option\n");
		};
	}while(true);
	return 0;
}
