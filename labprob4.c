#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ID;
    char Name[50];
    int subject1;
    int subject2;
    int subject3;
} Student;

void appendStudentRecord() {
    FILE *fp = fopen("students.txt", "a"); // Open in append mode
    if (fp == NULL) {
        printf("Error opening file for appending.\n");
        return;
    }

    Student student;
    printf("Appending student:\n");
    scanf("%d, %s, %d, %d, %d", &student.ID, student.Name, &student.subject1, &student.subject2, &student.subject3);

    fprintf(fp, "%d %s %d %d %d\n", student.ID, student.Name, student.subject1, student.subject2, student.subject3);

    fclose(fp);
    printf("Student record appended.\n");
}

void displayStudentRecords() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    printf("Student Records:\n");

    Student student;
    while (fscanf(fp, "%d %s %d %d %d", &student.ID, student.Name, &student.subject1, &student.subject2, &student.subject3) != EOF) {
        printf("%d %s %d %d %d\n", student.ID, student.Name, student.subject1, student.subject2, student.subject3);
    }

    fclose(fp);
}

int main() {
    int choice;
    do {
        printf("\n1. Append Student Record\n2. Display Student Records\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                appendStudentRecord();
                break;
            case 2:
                displayStudentRecords();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}
