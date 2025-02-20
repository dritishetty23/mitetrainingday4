#include <stdio.h>

struct Employee_t {
    int id;
    char name[255];
    float salary;
    char department[50];
};

typedef struct Employee_t Employee;

void readEmployees(Employee emp[], int n);
void displayEmployees(Employee emp[], int n);
Employee findHighestSalary(Employee emp[], int n);

int main() {
    int employeeCount;
    printf("Enter number of employees:");
    scanf("%d", &employeeCount);

    Employee employees[1000];
    readEmployees(employees, employeeCount);
    displayEmployees(employees, employeeCount);
    Employee highestSalariedEmployee = findHighestSalary(employees, employeeCount);

    printf("Employee with highest salary: %s, %.2f (%s)\n",
           highestSalariedEmployee.name,
           highestSalariedEmployee.salary,
           highestSalariedEmployee.department);

    return 0;
}

void readEmployees(Employee emp[], int n) {
    // Implement reading employee data here
}

void displayEmployees(Employee emp[], int n) {
    // Implement displaying employee data here
}

Employee findHighestSalary(Employee emp[], int n) {
    // Implement finding the employee with the highest salary here
    // You'll need to return an Employee struct
    // (e.g., return employees[0]; if you just want to return the first employee)
}
