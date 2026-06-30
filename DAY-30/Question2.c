/* Write a program to Create mini library system */

#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[50];
    int available;
};

struct Book library[MAX_BOOKS];
int bookCount = 0;
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();

int main() {
    int choice;
    while (1) {
        printf("\n=================================");
        printf("\n=== MINI LIBRARY SYSTEM MENU ===");
        printf("\n=================================");
        printf("\n1. Add a New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Book by ID");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("\nExiting library system. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nLibrary is full! Cannot add more books.\n");
        return;
    }
    struct Book newBook;
    printf("\nEnter Unique Book ID (Integer): ");
    scanf("%d", &newBook.id);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == newBook.id) {
            printf("\nError: A book with ID %d already exists!\n", newBook.id);
            return;
        }
    }
    getchar(); 
    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; 
    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; 
    newBook.available = 1; 
    library[bookCount] = newBook;
    bookCount++;
    printf("\nBook added successfully!\n");
}

void displayBooks() {
    if (bookCount == 0) {
        printf("\nNo books available in the library yet.\n");
        return;
    }
    printf("\n%-10s %-30s %-25s %-15s", "ID", "Title", "Author", "Status");
    printf("\n--------------------------------------------------------------------------------");
    for (int i = 0; i < bookCount; i++) {
        printf("\n%-10d %-30s %-25s %-15s", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].available ? "Available" : "Issued");
    }
    printf("\n");
}

void searchBook() {
    if (bookCount == 0) {
        printf("\nThe library is completely empty.\n");
        return;
    }
    int searchId;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &searchId);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            printf("\n--- Book Found ---");
            printf("\nID: %d", library[i].id);
            printf("\nTitle: %s", library[i].title);
            printf("\nAuthor: %s", library[i].author);
            printf("\nStatus: %s\n", library[i].available ? "Available" : "Issued");
            return;
        }
    }
    printf("\nBook with ID %d not found.\n", searchId);
}

void issueBook() {
    int issueId;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &issueId);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == issueId) {
            if (library[i].available == 1) {
                library[i].available = 0;
                printf("\nBook '%s' issued successfully!\n", library[i].title);
            } else {
                printf("\nSorry, this book is already issued to someone else.\n");
            }
            return;
        }
    }
    printf("\nBook ID not found.\n");
}

void returnBook() {
    int returnId;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &returnId);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == returnId) {
            if (library[i].available == 0) {
                library[i].available = 1; 
                printf("\nBook '%s' returned successfully!\n", library[i].title);
            } else {
                printf("\nThis book was already marked as available inside the system.\n");
            }
            return;
        }
    }
    printf("\nBook ID not found.\n");
}
