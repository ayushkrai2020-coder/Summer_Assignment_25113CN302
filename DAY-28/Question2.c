/* Write a program to Create bank account system */

#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

void createAccount(Account accounts[], int *totalAccounts);
void deposit(Account accounts[], int totalAccounts);
void withdraw(Account accounts[], int totalAccounts);
void checkBalance(Account accounts[], int totalAccounts);
int findAccount(Account accounts[], int totalAccounts, int accNum);

int main() {
    Account accounts[MAX_ACCOUNTS];
    int totalAccounts = 0;
    int choice;
    do {
        printf("\n=============================\n");
        printf(" BANK ACCOUNT MANAGEMENT SYSTEM \n");
        printf("=============================\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount(accounts, &totalAccounts);
                break;
            case 2:
                deposit(accounts, totalAccounts);
                break;
            case 3:
                withdraw(accounts, totalAccounts);
                break;
            case 4:
                checkBalance(accounts, totalAccounts);
                break;
            case 5:
                printf("\nThank you for banking with us. Goodbye!\n");
                break;
            default:
                printf("\nInvalid selection! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);
    return 0;
}

void createAccount(Account accounts[], int *totalAccounts) {
    if (*totalAccounts >= MAX_ACCOUNTS) {
        printf("\nError: System storage full. Cannot add more accounts.\n");
        return;
    }
    Account newAccount;
    printf("\nEnter Account Number (Integer): ");
    scanf("%d", &newAccount.accountNumber);
    if (findAccount(accounts, *totalAccounts, newAccount.accountNumber) != -1) {
        printf("\nError: An account with this number already exists!\n");
        return;
    }
    printf("Enter Account Holder Name: ");
    getchar();
    fgets(newAccount.name, sizeof(newAccount.name), stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = '\0'; 
    printf("Enter Initial Deposit Amount: $");
    scanf("%f", &newAccount.balance);
    if (newAccount.balance < 0) {
        printf("\nError: Initial deposit cannot be negative!\n");
        return;
    }
    accounts[*totalAccounts] = newAccount;
    (*totalAccounts)++;
    printf("\nSuccess: Account created successfully!\n");
}

void deposit(Account accounts[], int totalAccounts) {
    int accNum;
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);
    int index = findAccount(accounts, totalAccounts, accNum);
    if (index == -1) {
        printf("\nError: Account not found.\n");
        return;
    }
    printf("Enter Deposit Amount: $");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("\nError: Deposit amount must be greater than zero.\n");
        return;
    }
    accounts[index].balance += amount;
    printf("\nSuccess: $%.2f deposited. New Balance: $%.2f\n", amount, accounts[index].balance);
}

void withdraw(Account accounts[], int totalAccounts) {
    int accNum;
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);
    int index = findAccount(accounts, totalAccounts, accNum);
    if (index == -1) {
        printf("\nError: Account not found.\n");
        return;
    }
    printf("Enter Withdrawal Amount: $");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("\nError: Withdrawal amount must be greater than zero.\n");
        return;
    }
    if (amount > accounts[index].balance) {
        printf("\nError: Insufficient funds! Available balance: $%.2f\n", accounts[index].balance);
        return;
    }
    accounts[index].balance -= amount;
    printf("\nSuccess: $%.2f withdrawn. New Balance: $%.2f\n", amount, accounts[index].balance);
}

void checkBalance(Account accounts[], int totalAccounts) {
    int accNum;
    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);
    int index = findAccount(accounts, totalAccounts, accNum);
    if (index == -1) {
        printf("\nError: Account not found.\n");
        return;
    }
    printf("\n--- Account Statement ---");
    printf("\nAccount Holder : %s", accounts[index].name);
    printf("\nAccount Number : %d", accounts[index].accountNumber);
    printf("\nCurrent Balance: $%.2f\n", accounts[index].balance);
}

int findAccount(Account accounts[], int totalAccounts, int accNum) {
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            return i; 
        }
    }
    return -1;
}
