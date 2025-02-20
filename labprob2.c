#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ID;
    char Name[50];
    float Salary;
} Employee;

void writeToFile(Employee emp[], int n) {
    FILE *fp = fopen("employees.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %.2f\n", emp[i].ID, emp[i].Name, emp[i].Salary);
    }

    fclose(fp);
    printf("Employee data written to file.\n");
}

void readFromFile() {
    FILE *fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    printf("Employees Data from File:\n");

    Employee emp;
    while (fscanf(fp, "%d %s %f", &emp.ID, emp.Name, &emp.Salary) != EOF) {
        printf("%d %s %.2f\n", emp.ID, emp.Name, emp.Salary);
    }

    fclose(fp);
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    Employee employees[n];

    printf("Enter details (ID, Name, Salary):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %s %f", &employees[i].ID, employees[i].Name, &employees[i].Salary);
    }

    writeToFile(employees, n);
    readFromFile();

    return 0;
}
