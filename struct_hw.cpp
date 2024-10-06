#include <iostream>
#include <string.h>
#include <vector>

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
    scanf("%d",&choice);
    printf("-------------------------\n");
    return choice;
}
/*
Requirements:
Add Employee: The user should be able to add new employees until they choose to stop.
Prompt the user for all necessary details.
*/
/*
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
    	printf("Employee %03ld\n"
               "id: %03d\n"
               "name: %s\n"
               "age: %d\n"
               "position: %s\n"
               "salary: %f\n"
               ,i+1, emplist[i].id, emplist[i].name, emplist[i].age, emplist[i].position, emplist[i].salary);
        printf("-------------------------\n");
    }
}
/*
3. Display Employee with Highest Salary
4. Display Average Salary
5. Find Employee by ID
6. Exit
Enter your choice: 1
Enter employee ID: 101
Enter employee name: John Doe
Enter employee age: 35
Enter employee position: Manager
Enter employee salary: 5000
Employee added successfully!
1. Add Employee
2. Display All Employees
3. Display Employee with Highest Salary
4. Display Average Salary
5. Find Employee by ID
6. Exit
Enter your choice: 2
ID: 101
Name: John Doe
Age: 35
Position: Manager
Salary: 5000.00
Optional Enhancements:
Allow sorting the list of employees by salary, age, or name.
Save and load employee data from a file.
This assignment should help you practice working with structs, arrays or vectors, and
basic input/output in C++.
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
                showEmp(emplist);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("you have chosen %d",choice);
                return 0;
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
