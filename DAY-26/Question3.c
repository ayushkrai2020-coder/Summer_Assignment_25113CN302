/* Write a program to Create ATM simulation */

#include <stdio.h>
#include <stdbool.h>

void displayMenu();
void checkBalance(float balance);
float depositMoney(float balance);
float withdrawMoney(float balance);

int main() {
    const int DEFAULT_PIN = 1234;
    float accountBalance = 5000.00; 
    int enteredPin;
    int pinAttempts = 0;
    const int MAX_ATTEMPTS = 3;
    bool isAuthenticated = false;
    int menuChoice;
    char continueTransaction;
    printf("===========================================\n");
    printf("        WELCOME TO THE ATM SIMULATOR       \n");
    printf("===========================================\n");
    while (pinAttempts < MAX_ATTEMPTS) {
        printf("\nPlease enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);
        if (enteredPin == DEFAULT_PIN) {
            isAuthenticated = true;
            break;
        } else {
            pinAttempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n", MAX_ATTEMPTS - pinAttempts);
        }
    }
    if (!isAuthenticated) {
        printf("\nToo many incorrect attempts. Your card has been blocked.\n");
        printf("Please contact customer service. Goodbye!\n");
        return 0;
    }
    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1:
                checkBalance(accountBalance);
                break;
            case 2:
                accountBalance = depositMoney(accountBalance);
                break;
            case 3:
                accountBalance = withdrawMoney(accountBalance);
                break;
            case 4:
                printf("\nThank you for using our ATM services. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid option. Please choose a valid service.\n");
        }
        printf("\nWould you like to perform another transaction? (y/n): ");
        scanf(" %c", &continueTransaction); 

    } while (continueTransaction == 'y' || continueTransaction == 'Y');

    printf("\nThank you for choosing us. Have a wonderful day!\n");
    return 0;
}

void displayMenu() {
    printf("\n-------------------------------------------\n");
    printf("                ATM MAIN MENU              \n");
    printf("-------------------------------------------\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Cash\n");
    printf("3. Withdraw Cash\n");
    printf("4. Exit\n");
    printf("-------------------------------------------\n");
}
void checkBalance(float balance) {
    printf("\n[BALANCE ENQUIRY]");
    printf("\nYour current available balance is: $%.2f\n", balance);
}
float depositMoney(float balance) {
    float depositAmount;
    printf("\n[CASH DEPOSIT]");
    printf("\nEnter the amount to deposit: $");
    scanf("%f", &depositAmount);

    if (depositAmount <= 0) {
        printf("Invalid amount. Deposit must be greater than $0.\n");
    } else {
        balance += depositAmount;
        printf("Successfully deposited: $%.2f\n", depositAmount);
        printf("Your updated balance is: $%.2f\n", balance);
    }
    return balance;
}
float withdrawMoney(float balance) {
    float withdrawAmount;
    printf("\n[CASH WITHDRAWAL]");
    printf("\nEnter the amount to withdraw: $");
    scanf("%f", &withdrawAmount);
    if (withdrawAmount <= 0) {
        printf("Invalid amount. Withdrawal must be greater than $0.\n");
    } else if (withdrawAmount > balance) {
        printf("Transaction Declined: Insufficient funds!\n");
        printf("Your current balance is: $%.2f\n", balance);
    } else {
        balance -= withdrawAmount;
        printf("Please collect your cash: $%.2f\n", withdrawAmount);
        printf("Your updated balance is: $%.2f\n", balance);
    }
    return balance;
}
