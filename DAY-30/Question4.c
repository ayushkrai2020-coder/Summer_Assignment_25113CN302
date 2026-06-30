/* Write a program to Develop complete mini project using arrays, strings and functions */

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

void displayMenu();
void addStudent(char names[][NAME_LENGTH], int rolls[], float gpas[], int *count);
void displayStudents(char names[][NAME_LENGTH], int rolls[], float gpas[], int count);
void searchStudent(char names[][NAME_LENGTH], int rolls[], float gpas[], int count);
void updateGpa(int rolls[], float gpas[], int count);

int main() {
    char studentNames[MAX_STUDENTS][NAME_LENGTH];
    int rollNumbers[MAX_STUDENTS];
    float studentGpas[MAX_STUDENTS];
    int studentCount = 0;
    int choice;
    printf("=== Welcome to the Student Database System ===\n");
    while (1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input type. Exiting program.\n");
            break;
        }
        getchar(); 
        switch (choice) {
            case 1:
                addStudent(studentNames, rollNumbers, studentGpas, &studentCount);
                break;
            case 2:
                displayStudents(studentNames, rollNumbers, studentGpas, studentCount);
                break;
            case 3:
                searchStudent(studentNames, rollNumbers, studentGpas, studentCount);
                break;
            case 4:
                updateGpa(rollNumbers, studentGpas, studentCount);
                break;
            case 5:
                printf("\nExiting the system. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please choose between 1 and 5.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n-------------------------------\n");
    printf("1. Add New Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by Name\n");
    printf("4. Update Student GPA\n");
    printf("5. Exit Application\n");
    printf("-------------------------------\n");
}

void addStudent(char names[][NAME_LENGTH], int rolls[], float gpas[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nDatabase is full! Cannot add more students.\n");
        return;
    }
    printf("\nEnter Student Name: ");
    fgets(names[*count], NAME_LENGTH, stdin);
    names[*count][strcspn(names[*count], "\n")] = '\0';
    printf("Enter Roll Number: ");
    scanf("%d", &rolls[*count]);
    printf("Enter GPA (0.0 - 4.0): ");
    scanf("%f", &gpas[*count]);
    (*count)++;
    printf("\nStudent added successfully!\n");
}

void displayStudents(char names[][NAME_LENGTH], int rolls[], float gpas[], int count) {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }
    printf("\n================= STUDENT LIST =================\n");
    printf("%-5s %-30s %-10s %-5s\n", "No.", "Name", "Roll No", "GPA");
    printf("------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-30s %-10d %-5.2f\n", i + 1, names[i], rolls[i], gpas[i]);
    }
    printf("================================================\n");
}

void searchStudent(char names[][NAME_LENGTH], int rolls[], float gpas[], int count) {
    if (count == 0) {
        printf("\nDatabase is empty. Nothing to search.\n");
        return;
    }
    char searchName[NAME_LENGTH];
    int found = 0;
    printf("\nEnter the student name to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], searchName) == 0) { 
            if (!found) {
                printf("\nMatch Found:\n");
                printf("%-30s %-10s %-5s\n", "Name", "Roll No", "GPA");
                printf("------------------------------------------------\n");
            }
            printf("%-30s %-10d %-5.2f\n", names[i], rolls[i], gpas[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("\nNo student found with the name \"%s\".\n", searchName);
    }
}

void updateGpa(int rolls[], float gpas[], int count) {
    if (count == 0) {
        printf("\nDatabase is empty. No records to update.\n");
        return;
    }
    int targetRoll;
    int found = 0;
    printf("\nEnter Roll Number to update GPA: ");
    scanf("%d", &targetRoll);
    for (int i = 0; i < count; i++) {
        if (rolls[i] == targetRoll) {
            printf("Current GPA for Roll No %d is: %.2f\n", rolls[i], gpas[i]);
            printf("Enter New GPA: ");
            scanf("%f", &gpas[i]);
            printf("\nGPA updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nRoll Number %d not found.\n", targetRoll);
    }
}
