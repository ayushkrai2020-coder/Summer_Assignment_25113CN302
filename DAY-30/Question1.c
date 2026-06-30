/* Write a program to Create student record system using arrays and strings */

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

struct Student {
    int rollNumber;
    char name[NAME_LENGTH];
    float marks;
};

void addStudent(struct Student records[], int *count);
void displayStudents(const struct Student records[], int count);
void searchStudent(const struct Student records[], int count);

int main() {
    struct Student records[MAX_STUDENTS]; 
    int count = 0;                     
    int choice;
    do {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add New Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (choice) {
            case 1:
                addStudent(records, &count);
                break;
            case 2:
                displayStudents(records, count);
                break;
            case 3:
                searchStudent(records, count);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose an option between 1 and 4.\n");
        }
    } while (choice != 4);
    return 0;
}

void addStudent(struct Student records[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("System Database Full! Cannot add more records.\n");
        return;
    }
    printf("\n--- Add Student Details ---\n");
    printf("Enter Roll Number: ");
    scanf("%d", &records[*count].rollNumber);
    while (getchar() != '\n'); 
    printf("Enter Student Name: ");
    fgets(records[*count].name, NAME_LENGTH, stdin);
    size_t len = strlen(records[*count].name);
    if (len > 0 && records[*count].name[len - 1] == '\n') {
        records[*count].name[len - 1] = '\0';
    }
    printf("Enter Marks: ");
    scanf("%f", &records[*count].marks);
    (*count)++; 
    printf("Record added successfully!\n");
}

void displayStudents(const struct Student records[], int count) {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }
    printf("\n%-10s %-30s %-10s\n", "Roll No", "Name", "Marks");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-10.2f\n", records[i].rollNumber, records[i].name, records[i].marks);
    }
}

void searchStudent(const struct Student records[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }
    int targetRoll;
    int found = 0;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &targetRoll);
    for (int i = 0; i < count; i++) {
        if (records[i].rollNumber == targetRoll) {
            printf("\n--- Record Found ---\n");
            printf("Roll Number : %d\n", records[i].rollNumber);
            printf("Name        : %s\n", records[i].name);
            printf("Marks       : %.2f\n", records[i].marks);
            found = 1;
            break; 
        }
    }
    if (!found) {
        printf("Student with Roll Number %d not found.\n", targetRoll);
    }
}
