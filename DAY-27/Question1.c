/* Write a program to Create student record management system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int rollNumber;
    char name[50];
    float cgpa;
    char branch[30];
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent();
void displayAll();
void searchStudent();
void updateStudent();
void deleteStudent();
void clearInputBuffer();

int main() {
    int choice;
    while (1) {
        printf("\n=== STUDENT RECORD MANAGEMENT SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: 
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Error: Database is full. Cannot add more students.\n");
        return;
    }
    Student s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.rollNumber);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == s.rollNumber) {
            printf("Error: A student with Roll Number %d already exists.\n", s.rollNumber);
            return;
        }
    }
    clearInputBuffer(); 
    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; 
    printf("Enter Branch/Department: ");
    fgets(s.branch, sizeof(s.branch), stdin);
    s.branch[strcspn(s.branch, "\n")] = 0;
    printf("Enter CGPA: ");
    scanf("%f", &s.cgpa);
    students[studentCount] = s;
    studentCount++;
    printf("Record added successfully!\n");
}

void displayAll() {
    if (studentCount == 0) {
        printf("\nNo student records available.\n");
        return;
    }
    printf("\n%-10s %-25s %-15s %-5s\n", "Roll No", "Name", "Branch", "CGPA");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-10d %-25s %-15s %-5.2f\n", 
               students[i].rollNumber, students[i].name, students[i].branch, students[i].cgpa);
    }
}

void searchStudent() {
    if (studentCount == 0) {
        printf("\nNo records to search.\n");
        return;
    }
    int roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name:        %s\n", students[i].name);
            printf("Branch:      %s\n", students[i].branch);
            printf("CGPA:        %.2f\n", students[i].cgpa);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll);
}

void updateStudent() {
    if (studentCount == 0) {
        printf("\nNo records available to update.\n");
        return;
    }
    int roll;
    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            printf("\nCurrent details found. Enter new information:\n");
            clearInputBuffer();
            printf("Enter New Name: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0;
            printf("Enter New Branch: ");
            fgets(students[i].branch, sizeof(students[i].branch), stdin);
            students[i].branch[strcspn(students[i].branch, "\n")] = 0;
            printf("Enter New CGPA: ");
            scanf("%f", &students[i].cgpa);
            printf("Record updated successfully!\n");
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll);
}

void deleteStudent() {
    if (studentCount == 0) {
        printf("\nNo records available to delete.\n");
        return;
    }
    int roll;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Record deleted successfully!\n");
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll);
}
