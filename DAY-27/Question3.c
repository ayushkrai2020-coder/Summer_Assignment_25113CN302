/* Write a program to Create salary management system */

#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    float basic_salary;
    float da;           
    float hra;          
    float pf;          
    float gross_salary;
    float net_salary;
};

struct Employee emp_list[MAX_EMPLOYEES];
int emp_count = 0;

void addEmployee();
void displayAllEmployees();
void searchEmployee();
void calculateSalaryComponents(struct Employee *emp);

int main() {
    int choice;
    while (1) {
        printf("\n=================================");
        printf("\n     SALARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Salary Slips");
        printf("\n3. Search Employee Pay Slip");
        printf("\n4. Exit");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                printf("\nExiting system. Thank you!\n");
                return 0;
            default:
                printf("\nInvalid selection! Please choose a valid option.\n");
        }
    }
    return 0;
}

void calculateSalaryComponents(struct Employee *emp) {
    emp->da = emp->basic_salary * 0.40;  
    emp->hra = emp->basic_salary * 0.20; 
    emp->pf = emp->basic_salary * 0.12;  
    emp->gross_salary = emp->basic_salary + emp->da + emp->hra;
    emp->net_salary = emp->gross_salary - emp->pf;
}

void addEmployee() {
    if (emp_count >= MAX_EMPLOYEES) {
        printf("\nSystem database is full! Cannot add more records.\n");
        return;
    }
    struct Employee new_emp;
    printf("\nEnter Employee ID (Integer): ");
    scanf("%d", &new_emp.id);
    getchar(); 
    printf("Enter Employee Name: ");
    fgets(new_emp.name, sizeof(new_emp.name), stdin);
    new_emp.name[strcspn(new_emp.name, "\n")] = 0;
    printf("Enter Basic Monthly Salary: ");
    scanf("%f", &new_emp.basic_salary);
    calculateSalaryComponents(&new_emp);
    emp_list[emp_count] = new_emp;
    emp_count++;
    printf("\nRecord added successfully!\n");
}

void displayAllEmployees() {
    if (emp_count == 0) {
        printf("\nNo employee records found in the system.\n");
        return;
    }
    printf("\n%-5s %-20s %-10s %-8s %-8s %-8s %-10s", "ID", "Name", "Basic", "DA(40%%)", "HRA(20%%)", "PF(12%%)", "Net Pay");
    printf("\n--------------------------------------------------------------------------------");
    for (int i = 0; i < emp_count; i++) {
        printf("\n%-5d %-20s %-10.2f %-8.2f %-8.2f %-8.2f %-10.2f", 
               emp_list[i].id, 
               emp_list[i].name, 
               emp_list[i].basic_salary, 
               emp_list[i].da, 
               emp_list[i].hra, 
               emp_list[i].pf, 
               emp_list[i].net_salary);
    }
    printf("\n--------------------------------------------------------------------------------\n");
}

void searchEmployee() {
    if (emp_count == 0) {
        printf("\nNo data available to search.\n");
        return;
    }
    int search_id;
    int found = 0;
    printf("\nEnter Employee ID to look up: ");
    scanf("%d", &search_id);
    for (int i = 0; i < emp_count; i++) {
        if (emp_list[i].id == search_id) {
            found = 1;
            printf("\n=================================");
            printf("\n      SALARY SLIP FOR ID: %d     ", emp_list[i].id);
            printf("\n=================================");
            printf("\nEmployee Name     : %s", emp_list[i].name);
            printf("\nBasic Earnings    : $%.2f", emp_list[i].basic_salary);
            printf("\nDA Allowances     : $%.2f", emp_list[i].da);
            printf("\nHRA Allowances    : $%.2f", emp_list[i].hra);
            printf("\n---------------------------------");
            printf("\nGross Pay Total   : $%.2f", emp_list[i].gross_salary);
            printf("\n---------------------------------");
            printf("\nPF Deductions     : $%.2f", emp_list[i].pf);
            printf("\n---------------------------------");
            printf("\nNET TAKE-HOME PAY : $%.2f", emp_list[i].net_salary);
            printf("\n=================================\n");
            break;
        }
    }
    if (!found) {
        printf("\nEmployee with ID %d not found.\n", search_id);
    }
}
