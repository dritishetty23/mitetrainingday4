#include <stdio.h>

typedef struct {
    int subject1;
    int subject2;
    int subject3;
} Marks;

typedef struct {
    int ID;
    char Name[50];
    Marks marks;
    int totalMarks;
    float averageMarks;
    char grade;
} Student;

void readStudents(Student students[], int n) {
    printf("Enter details (ID, Name, Marks in 3 subjects):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d %d %d", &students[i].ID, students[i].Name, 
              &students[i].marks.subject1, &students[i].marks.subject2, &students[i].marks.subject3);
    }
}

void calculateGrades(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        students[i].totalMarks = students[i].marks.subject1 + students[i].marks.subject2 + students[i].marks.subject3;
        students[i].averageMarks = (float)students[i].totalMarks / 3;

        if (students[i].averageMarks >= 90) {
            students[i].grade = 'A';
        } else if (students[i].averageMarks >= 75) {
            students[i].grade = 'B';
        } else if (students[i].averageMarks >= 60) {
            students[i].grade = 'C';
        } else if (students[i].averageMarks >= 45) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }
    }
}

void displayStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s - Total: %d, Average: %.2f, Grade: %c\n", 
               students[i].Name, students[i].totalMarks, students[i].averageMarks, students[i].grade);
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    Student students[n]; // Variable length array, supported by C99 and later

    readStudents(students, n);
    calculateGrades(students, n);
    displayStudents(students, n);

    return 0;
}
