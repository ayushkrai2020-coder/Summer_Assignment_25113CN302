/* Write a program to Create library management system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    float price;
    int isAvailable;
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void displayMenu();
void addBook();
void viewBooks();
void searchBook();
void deleteBook();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid selection. Try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=================================");
    printf("\n    LIBRARY MANAGEMENT SYSTEM    ");
    printf("\n=================================");
    printf("\n1. Add New Book");
    printf("\n2. View All Books");
    printf("\n3. Search Book by Title");
    printf("\n4. Delete a Book");
    printf("\n5. Exit System");
    printf("\n=================================\n");
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nError: Library storage is full!\n");
        return;
    }
    struct Book newBook;
    newBook.id = bookCount + 1; 
    printf("\nEnter Book Details:\n");
    printf("Title: ");
    getchar(); 
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; 
    printf("Author: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; 
    printf("Price: ");
    if (scanf("%f", &newBook.price) != 1) {
        printf("\nInvalid price input. Operation cancelled.\n");
        while (getchar() != '\n');
        return;
    }
    newBook.isAvailable = 1;
    library[bookCount] = newBook;
    bookCount++;
    printf("\nSuccess: Book added cleanly! Assigned ID: %d\n", newBook.id);
}

void viewBooks() {
    if (bookCount == 0) {
        printf("\nThe library contains no registered records.\n");
        return;
    }
    printf("\n%-5s %-30s %-25s %-10s %-12s\n", "ID", "Title", "Author", "Price", "Status");
    printf("---------------------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-5d %-30s %-25s $%-9.2f %-12s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].price, 
               library[i].isAvailable ? "Available" : "Checked Out");
    }
}

void searchBook() {
    if (bookCount == 0) {
        printf("\nThe library contains no registered records.\n");
        return;
    }
    char searchTitle[100];
    int found = 0;
    printf("\nEnter book title to search: ");
    getchar();
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;
    printf("\nSearch Results:\n");
    for (int i = 0; i < bookCount; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {
            printf("\nID: %d\nTitle: %s\nAuthor: %s\nPrice: $%.2f\nStatus: %s\n", 
                   library[i].id, library[i].title, library[i].author, 
                   library[i].price, library[i].isAvailable ? "Available" : "Checked Out");
            found = 1;
        }
    }
    if (!found) {
        printf("No records matched your search title.\n");
    }
}

void deleteBook() {
    if (bookCount == 0) {
        printf("\nThe library contains no registered records.\n");
        return;
    }
    int deleteId;
    int foundIndex = -1;
    printf("\nEnter Book ID to delete: ");
    if (scanf("%d", &deleteId) != 1) {
        printf("\nInvalid ID entry.\n");
        while (getchar() != '\n');
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == deleteId) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex == -1) {
        printf("\nError: Assigned ID not found.\n");
        return;
    }
    for (int i = foundIndex; i < bookCount - 1; i++) {
        library[i] = library[i + 1];
    }
    bookCount--;
    printf("\nSuccess: Record deleted cleanly.\n");
}
