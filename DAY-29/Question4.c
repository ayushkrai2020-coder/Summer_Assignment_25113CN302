/* Write a program to Create inventory management system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define FILE_NAME "database.txt"

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int product_count = 0;

void load_from_file();
void save_to_file();
void add_product();
void view_inventory();
void search_product();
void update_stock();
void delete_product();
void clear_input_buffer();

int main() {
    int choice;
    load_from_file(); 
    while (1) {
        printf("\n=== INVENTORY MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Product\n");
        printf("2. View All Products\n");
        printf("3. Search Product by ID\n");
        printf("4. Update Stock Quantity\n");
        printf("5. Delete a Product\n");
        printf("6. Save & Exit\n");
        printf("Enter your choice (1-6): ");  
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;
        }
        switch (choice) {
            case 1: add_product(); break;
            case 2: view_inventory(); break;
            case 3: search_product(); break;
            case 4: update_stock(); break;
            case 5: delete_product(); break;
            case 6: 
                save_to_file();
                printf("Data successfully saved. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please pick an option between 1 and 6.\n");
        }
    }
    return 0;
}

void load_from_file() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return;
    }
    product_count = 0;
    while (fscanf(file, "%d,%49[^,],%d,%f\n", 
                  &inventory[product_count].id, 
                  inventory[product_count].name, 
                  &inventory[product_count].quantity, 
                  &inventory[product_count].price) == 4) {
        product_count++;
        if (product_count >= MAX_PRODUCTS) break;
    }
    fclose(file);
}

void save_to_file() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error: Could not open file to save data.\n");
        return;
    }
    for (int i = 0; i < product_count; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n", 
                inventory[i].id, 
                inventory[i].name, 
                inventory[i].quantity, 
                inventory[i].price);
    }
    fclose(file);
}

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    Product new_prod;
    printf("\nEnter Product ID (Integer): ");
    scanf("%d", &new_prod.id);
    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == new_prod.id) {
            printf("Error: A product with ID %d already exists!\n", new_prod.id);
            return;
        }
    }
    printf("Enter Product Name: ");
    clear_input_buffer();
    scanf("%49[^\n]", new_prod.name); 
    printf("Enter Quantity: ");
    scanf("%d", &new_prod.quantity);
    printf("Enter Price: ");
    scanf("%f", &new_prod.price);
    inventory[product_count] = new_prod;
    product_count++;
    printf("Product added successfully!\n");
}

void view_inventory() {
    if (product_count == 0) {
        printf("\nYour inventory is completely empty.\n");
        return;
    }
    printf("\n-------------------------------------------------------------\n");
    printf("%-10s %-25s %-12s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < product_count; i++) {
        printf("%-10d %-25s %-12d $%-9.2f\n", 
               inventory[i].id, 
               inventory[i].name, 
               inventory[i].quantity, 
               inventory[i].price);
    }
    printf("-------------------------------------------------------------\n");
}

void search_product() {
    int search_id;
    printf("\nEnter the Product ID to search: ");
    scanf("%d", &search_id);
    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == search_id) {
            printf("\nProduct Found:\n");
            printf("ID: %d\nName: %s\nStock: %d\nPrice: $%.2f\n", 
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Product with ID %d not found.\n", search_id);
}

void update_stock() {
    int search_id, new_qty;
    printf("\nEnter the Product ID to update: ");
    scanf("%d", &search_id);
    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == search_id) {
            printf("Current stock for %s is %d. Enter new quantity: ", inventory[i].name, inventory[i].quantity);
            scanf("%d", &new_qty);
            inventory[i].quantity = new_qty;
            printf("Stock updated successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found.\n", search_id);
}

void delete_product() {
    int search_id;
    printf("\nEnter the Product ID to delete: ");
    scanf("%d", &search_id);
    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == search_id) {
            for (int j = i; j < product_count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            product_count--;
            printf("Product successfully deleted from inventory.\n");
            return;
        }
    }
    printf("Product with ID %d not found.\n", search_id);
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
