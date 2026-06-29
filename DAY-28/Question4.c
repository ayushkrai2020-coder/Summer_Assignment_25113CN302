/* Write a program to Create contact management system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.dat"

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

void addContact();
void listContacts();
void searchContact();
void updateContact();
void deleteContact();
void clearInputBuffer();

int main() {
    int choice;
    while (1) {
        printf("\n=== CONTACT MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Contact\n");
        printf("2. List All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer(); 
        switch (choice) {
            case 1: addContact(); break;
            case 2: listContacts(); break;
            case 3: searchContact(); break;
            case 4: updateContact(); break;
            case 5: deleteContact(); break;
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

void addContact() {
    FILE *fp = fopen(FILE_NAME, "ab"); 
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    struct Contact newContact;
    printf("\nEnter Name: ");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0';
    printf("Enter Phone Number: ");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';
    printf("Enter Email Address: ");
    fgets(newContact.email, sizeof(newContact.email), stdin);
    newContact.email[strcspn(newContact.email, "\n")] = '\0';
    fwrite(&newContact, sizeof(struct Contact), 1, fp);
    fclose(fp);
    printf("Contact added successfully!\n");
}

void listContacts() {
    FILE *fp = fopen(FILE_NAME, "rb"); 
    if (fp == NULL) {
        printf("\nNo contacts found. The file is empty or missing.\n");
        return;
    }
    struct Contact c;
    int count = 1;
    printf("\n---------------------------------------------------------\n");
    printf("%-5s %-20s %-15s %-20s\n", "S.No", "Name", "Phone", "Email");
    printf("---------------------------------------------------------\n");
    while (fread(&c, sizeof(struct Contact), 1, fp) == 1) {
        printf("%-5d %-20s %-15s %-20s\n", count++, c.name, c.phone, c.email);
    }

    if (count == 1) {
        printf("No records found inside the file.\n");
    }
    printf("---------------------------------------------------------\n");
    fclose(fp);
} 

void searchContact() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo contacts available to search.\n");
        return;
    }
    char searchName[50];
    struct Contact c;
    int found = 0;
    printf("\nEnter Name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    printf("\n--- Search Results ---\n");
    while (fread(&c, sizeof(struct Contact), 1, fp) == 1) {
        if (strstr(c.name, searchName) != NULL) {
            printf("Name : %s\n", c.name);
            printf("Phone: %s\n", c.phone);
            printf("Email: %s\n---\n", c.email);
            found = 1;
        }
    }
    if (!found) {
        printf("No contact found matching '%s'.\n", searchName);
    }
    fclose(fp);
}

void updateContact() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\nNo contacts available to update.\n");
        return;
    }
    char targetName[50];
    struct Contact c;
    int found = 0;
    printf("\nEnter the exact Name of the contact to update: ");
    fgets(targetName, sizeof(targetName), stdin);
    targetName[strcspn(targetName, "\n")] = '\0';
    while (fread(&c, sizeof(struct Contact), 1, fp) == 1) {
        if (strcmp(c.name, targetName) == 0) {
            found = 1;
            printf("\n--- Existing Details ---\n");
            printf("Current Phone: %s\n", c.phone);
            printf("Current Email: %s\n", c.email);       
            printf("\nEnter New Name: ");
            fgets(c.name, sizeof(c.name), stdin);
            c.name[strcspn(c.name, "\n")] = '\0';
            printf("Enter New Phone: ");
            fgets(c.phone, sizeof(c.phone), stdin);
            c.phone[strcspn(c.phone, "\n")] = '\0';
            printf("Enter New Email: ");
            fgets(c.email, sizeof(c.email), stdin);
            c.email[strcspn(c.email, "\n")] = '\0';
            fseek(fp, -sizeof(struct Contact), SEEK_CUR);
            fwrite(&c, sizeof(struct Contact), 1, fp);
            printf("\nContact updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Contact matching '%s' not found.\n", targetName);
    }
    fclose(fp);
}

void deleteContact() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo contacts available to delete.\n");
        return;
    }
    FILE *tempFp = fopen("temp.dat", "wb");
    if (tempFp == NULL) {
        printf("System file handling error.\n");
        fclose(fp);
        return;
    }
    char targetName[50];
    struct Contact c;
    int found = 0;
    printf("\nEnter the exact Name of the contact to delete: ");
    fgets(targetName, sizeof(targetName), stdin);
    targetName[strcspn(targetName, "\n")] = '\0';
    while (fread(&c, sizeof(struct Contact), 1, fp) == 1) {
        if (strcmp(c.name, targetName) == 0) {
            found = 1;
        } else {
            fwrite(&c, sizeof(struct Contact), 1, tempFp);
        }
    }
    fclose(fp);
    fclose(tempFp);
    if (found) {
        remove(FILE_NAME);      
        rename("temp.dat", FILE_NAME);
        printf("Contact deleted successfully.\n");
    } else {
        remove("temp.dat");
        printf("Contact matching '%s' not found.\n", targetName);
    }
}
