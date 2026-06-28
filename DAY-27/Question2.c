/* Write a program to Create employee management system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.dat"

typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

void addEmployee();
void displayEmployees();
void searchEmployee();
void updateEmployee();
void deleteEmployee();
void clearInputBuffer();

int main() {
    int choice;
    while (1) {
        printf("\n=================================");
        printf("\n    EMPLOYEE MANAGEMENT SYSTEM   ");
        printf("\n=================================");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Records");
        printf("\n3. Search Employee Record");
        printf("\n4. Update Employee Record");
        printf("\n5. Delete Employee Record");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: 
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "ab"); 
    if (fp == NULL) {
        printf("\nError opening file!\n");
        return;
    }
    Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    clearInputBuffer();
    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; 
    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);
    fwrite(&emp, sizeof(Employee), 1, fp);
    fclose(fp);
    printf("\nRecord added successfully!\n");
}

void displayEmployees() {
    FILE *fp = fopen(FILE_NAME, "rb"); 
    if (fp == NULL) {
        printf("\nNo records found (or file missing).\n");
        return;
    }
    Employee emp;
    printf("\n%-10s %-20s %-20s %-10s", "ID", "Name", "Designation", "Salary");
    printf("\n--------------------------------------------------------------");
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        printf("\n%-10d %-20s %-20s %-10.2f", emp.id, emp.name, emp.designation, emp.salary);
    }
    printf("\n");
    fclose(fp);
}

void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }
    int searchId, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);
    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id == searchId) {
            printf("\nRecord Found!");
            printf("\nID: %d", emp.id);
            printf("\nName: %s", emp.name);
            printf("\nDesignation: %s", emp.designation);
            printf("\nSalary: %.2f\n", emp.salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
    fclose(fp);
}

void updateEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }
    int updateId, found = 0;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &updateId);
    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id == updateId) {
            found = 1;
            clearInputBuffer();
            printf("\nEnter New Name: ");
            fgets(emp.name, sizeof(emp.name), stdin);
            emp.name[strcspn(emp.name, "\n")] = 0;
            printf("Enter New Designation: ");
            fgets(emp.designation, sizeof(emp.designation), stdin);
            emp.designation[strcspn(emp.designation, "\n")] = 0;
            printf("Enter New Salary: ");
            scanf("%f", &emp.salary);
            fseek(fp, -sizeof(Employee), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, fp);
            printf("\nRecord updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("\nEmployee with ID %d not found.\n", updateId);
    }
    fclose(fp);
}

void deleteEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }
    FILE *tempFp = fopen("temp.dat", "wb");
    if (tempFp == NULL) {
        printf("\nError creating temporary file!\n");
        fclose(fp);
        return;
    }
    int deleteId, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);
    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id == deleteId) {
            found = 1; 
        } else {
            fwrite(&emp, sizeof(Employee), 1, tempFp);
        }
    }
    fclose(fp);
    fclose(tempFp);
    if (found) {
        remove(FILE_NAME);            
        rename("temp.dat", FILE_NAME); 
        printf("\nRecord deleted successfully!\n");
    } else {
        remove("temp.dat");         
        printf("\nEmployee with ID %d not found.\n", deleteId);
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
