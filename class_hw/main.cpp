#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstring>
#include "emp.hpp"
#include "validate.hpp"
#include "company.hpp"

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
// 6. Exit
void bye() {
	printf("Bye\n");
	exit(0);
}

int main(){
	company main;
	while(true){
		int choice = menu();
		switch(choice) {
			case 1:
				main.addEmp();
				break;
			case 2:
				main.showEmp();
				break;
			case 3:
				main.highest();
				break;
			case 4:
				main.avg();
				break;
			case 5:
				main.findid();
				break;
			case 6:
				bye();
				break;
			default:
				printf("invalid choice");
				break;
			}
	}
	return 0;
}
