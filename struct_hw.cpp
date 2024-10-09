#include <iostream>
#include <string.h>
#include <vector>
#include <limits>

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
*/
struct Emp {
    unsigned int id;
    char name[255];
    unsigned int age;
    char position[255];
    float salary;
};

/*
Create a menu that allows the user to:
Add a new employee to a list (array or vector).
Display all employees.
Display the employee with the highest salary.
Display the average salary of all employees.
Find and display an employee's details using their ID.
Exit the program.
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
            "Your choice: ");
    while (!(std::cin >> choice)) {
        std::cin.clear();  // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
        std::cout << "Your choice: ";
    }
    //    scanf("%d",&choice);
    printf("-------------------------\n");
    return choice;
}
/*
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

1. Add Employee
*/
void addEmp(std::vector<Emp>& emplist){
    char more;
    do {
        Emp e;
        printf("Give the Employee an ID: ");
        scanf("%d",&e.id);
        printf("Type the full name of the employee: ");
        scanf("%254s",e.name);
        printf("Insert employee age: ");
        scanf("%d",&e.age);
        printf("What is the employee position? ");
        scanf("%254s",e.position);
        printf("Insert employee salary: ");
        scanf("%f",&e.salary);
        emplist.push_back(e);
        printf("Do you want to add more employees? ");
        std::cin >> more;
        printf("-------------------------\n");
    } while (more == 'y' || more =='Y');
}

/*
2. Display All Employees
*/
void showEmp(const std::vector<Emp>& emplist) {
    for (size_t i = 0; i < emplist.size(); i++){
        printf("employee %03ld\n"
            "\tid: \t\t%03d\n"
            "\tname: \t\t%s\n"
            "\tage: \t\t%d\n"
            "\tposition: \t%s\n"
            "\tsalary: \t%f\n"
            ,i+1, emplist[i].id, emplist[i].name, emplist[i].age, emplist[i].position, emplist[i].salary);
        printf("-------------------------\n");
    }
}

/*
3. Display Employee with Highest Salary
*/
void highest(const std::vector<Emp>& emplist){
	float max = emplist[0].salary;
	int id;
	for(int i = 0; i < emplist.size(); ++i){
		if (emplist[i].salary>max){
			max = emplist[i].salary;
			id = i;
		}
	}
	printf("The highest paied employee is:\n"
		"\tid: \t\t%03d\n"
        "\tname: \t\t%s\n"
        "\tage: \t\t%d\n"
        "\tposition: \t%s\n"
        "\tsalary: \t%f\n"
		"-------------------------\n"
        ,emplist[id].id, emplist[id].name, emplist[id].age, emplist[id].position, emplist[id].salary);
}
/*
4. Display Average Salary
*/
void avg(const std::vector<Emp>& emplist){
	printf("\n");
}

/*
5. Find Employee by ID
*/

void findid(const std::vector<Emp>& emplist){
	printf("\n");
}
	
/*
6. Exit
*/
//    Emp* empArr = new Emp[1];
//    strcpy(empArr[0].id, "123456789");
//    strcpy(empArr[0].name, "Test Testington");
//    empArr[0].age = 40
//    strcpy(empArr[0].position, "The Man");
//    empArr[0].salary = 1000.5;
//          printEmp(empArr[0]);

int main(){
    std::vector<Emp> emplist;
    bool done = false;
    do {
        int choice = menu();
        switch (choice){
            case 1:
                addEmp(emplist);
                break;
            case 2:
				if (emplist.size() == 0){ printf("Create an employee first\n\n\n"); break;}
                showEmp(emplist);
                break;
            case 3:
				if (emplist.size() == 0){ printf("Create an employee first\n\n\n"); break;}
				highest(emplist);
                break;
            case 4:
				if (emplist.size() == 0){ printf("Create an employee first\n\n\n"); break;}
				avg(emplist);
                break;
            case 5:
				if (emplist.size() == 0){ printf("Create an employee first\n\n\n"); break;}
				findid(emplist);
                break;
            case 6:
                printf("Bye\n");
                done = true;
                break;
            default:
                printf("you have chosen an invalid option\n");
                break;
        };
    }while(!done);
    return 0;
}
