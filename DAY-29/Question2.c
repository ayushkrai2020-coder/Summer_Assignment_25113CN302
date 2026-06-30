/* Write a program to Create menu-driven array operations system */

#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

void createArray(int arr[], int *size);
void displayArray(const int arr[], int size);
void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
void searchElement(const int arr[], int size);

int main() {
    int arr[MAX_CAPACITY];
    int size = 0;
    int choice;
    while (1) {
        printf("\n==============================");
        printf("\n   ARRAY OPERATIONS SYSTEM    ");
        printf("\n==============================");
        printf("\n1. Create/Initialize Array");
        printf("\n2. Display Array Elements");
        printf("\n3. Insert Element at Position");
        printf("\n4. Delete Element from Position");
        printf("\n5. Search Element (Linear Search)");
        printf("\n6. Exit");
        printf("\n==============================");
        printf("\nEnter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input type! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (choice) {
            case 1:
                createArray(arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, &size);
                break;
            case 4:
                deleteElement(arr, &size);
                break;
            case 5:
                searchElement(arr, size);
                break;
            case 6:
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid selection! Please choose between 1 and 6.\n");
        }
    }
    return 0;
}

void createArray(int arr[], int *size) {
    int n;
    printf("\nEnter the number of elements (Max %d): ", MAX_CAPACITY);
    scanf("%d", &n);
    if (n < 0 || n > MAX_CAPACITY) {
        printf("Error: Size must be between 0 and %d.\n", MAX_CAPACITY);
        return;
    }
    *size = n;
    if (n > 0) {
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; i++) {
            printf("Element [%d]: ", i);
            scanf("%d", &arr[i]);
        }
        printf("Array created successfully!\n");
    } else {
        printf("Empty array initialized.\n");
    }
}

void displayArray(const int arr[], int size) {
    if (size == 0) {
        printf("\nThe array is currently empty!\n");
        return;
    }
    printf("\nArray Elements: [ ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
    printf("Current Size: %d / %d\n", size, MAX_CAPACITY);
}

void insertElement(int arr[], int *size) {
    if (*size >= MAX_CAPACITY) {
        printf("\nError: Array capacity reached! Cannot insert elements.\n");
        return;
    }
    int element, position;
    printf("\nEnter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position (1 to %d): ", *size + 1);
    scanf("%d", &position);
    if (position < 1 || position > *size + 1) {
        printf("Error: Invalid position choice!\n");
        return;
    }
    int index = position - 1;
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    (*size)++; 
    printf("Element inserted cleanly!\n");
}

void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("\nError: Array is already empty! Nothing to delete.\n");
        return;
    }
    int position;
    printf("\nEnter the position of the element to remove (1 to %d): ", *size);
    scanf("%d", &position);
    if (position < 1 || position > *size) {
        printf("Error: Invalid position choice!\n");
        return;
    }
    int index = position - 1;
    int removedValue = arr[index];
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Successfully removed %d from the array.\n", removedValue);
}

void searchElement(const int arr[], int size) {
    if (size == 0) {
        printf("\nThe array is empty! Nothing to search.\n");
        return;
    }
    int target, foundIndex = -1;
    printf("\nEnter the element value to search for: ");
    scanf("%d", &target);
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            foundIndex = i;
            break; 
        }
    }
    if (foundIndex != -1) {
        printf("Success: Value %d found at Array Index [%d] (Position %d).\n", target, foundIndex, foundIndex + 1);
    } else {
        printf("Not Found: Value %d does not exist in the array.\n", target);
    }
}
