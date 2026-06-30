/* Write a program to Create mini employee management system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

void addEmployee();
void viewEmployees();
void searchEmployee();
void deleteEmployee();
void updateEmployee();

const char* FILE_NAME = "employees.dat";

int main() {
    int choice;
    while (1) {
        printf("\n=== MINI EMPLOYEE MANAGEMENT SYSTEM ===\n");
        printf("1. Add Employee\n");
        printf("2. View All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Delete Employee Record\n");
        printf("5. Update Employee Salary/Designation\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: updateEmployee(); break;
            case 6: 
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

void addEmployee() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar();
    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0;
    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);
    fwrite(&emp, sizeof(Employee), 1, file);
    fclose(file);
    printf("Employee record added successfully!\n");
}

void viewEmployees() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo employee records found. Add some records first!\n");
        return;
    }
    Employee emp;
    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("------------------------------------------------------------------\n");
    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        printf("%-10d %-20s %-20s %-10.2f\n", emp.id, emp.name, emp.designation, emp.salary);
    }
    fclose(file);
}

void searchEmployee() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found!\n");
        return;
    }
    int searchId, found = 0;
    Employee emp;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);
    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        if (emp.id == searchId) {
            printf("\nRecord Found:\n");
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Designation: %s\n", emp.designation);
            printf("Salary: %.2f\n", emp.salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", searchId);
    }
    fclose(file);
}

void deleteEmployee() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found to delete!\n");
        return;
    }
    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }
    int targetId, found = 0;
    Employee emp;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &targetId);
    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        if (emp.id == targetId) {
            found = 1;
        } else {
            fwrite(&emp, sizeof(Employee), 1, tempFile);
        }
    }
    fclose(file);
    fclose(tempFile);
    if (found) {
        remove(FILE_NAME);
        rename("temp.dat", FILE_NAME);
        printf("Employee record deleted successfully!\n");
    } else {
        remove("temp.dat");
        printf("Employee with ID %d not found.\n", targetId);
    }
}

void updateEmployee() {
    FILE *file = fopen(FILE_NAME, "rb+"); 
    if (file == NULL) {
        printf("\nNo records found to update!\n");
        return;
    }
    int targetId, found = 0;
    Employee emp;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &targetId);
    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        if (emp.id == targetId) {
            found = 1;
            getchar(); 
            printf("Enter New Designation: ");
            fgets(emp.designation, sizeof(emp.designation), stdin);
            emp.designation[strcspn(emp.designation, "\n")] = 0;
            printf("Enter New Salary: ");
            scanf("%f", &emp.salary);
            fseek(file, -sizeof(Employee), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, file);
            printf("Employee record updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", targetId);
    }
    fclose(file);
}
