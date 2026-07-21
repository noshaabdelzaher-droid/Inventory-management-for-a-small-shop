#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Product products[MAX_PRODUCTS];
int count = 0;

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void addProduct(void) {
    if (count >= MAX_PRODUCTS) {
        printf("\nStorage is full. Cannot add more products.\n");
        return;
    }

    printf("\nEnter product ID: ");
    if (scanf("%d", &products[count].id) != 1) {
        printf("Invalid ID input.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    printf("Enter product name: ");
    if (fgets(products[count].name, sizeof(products[count].name), stdin) != NULL) {
        products[count].name[strcspn(products[count].name, "\n")] = '\0';
    } else {
        printf("Invalid name input.\n");
        return;
    }

    printf("Enter quantity: ");
    if (scanf("%d", &products[count].quantity) != 1) {
        printf("Invalid quantity input.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter price: ");
    if (scanf("%f", &products[count].price) != 1) {
        printf("Invalid price input.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();
    count++;
    printf("Product added successfully!\n");
}

void displayProducts(void) {
    printf("\n--- Product List ---\n");

    if (count == 0) {
        printf("No products available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", products[i].id);
        printf("Name: %s\n", products[i].name);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: %.2f\n", products[i].price);
        printf("----------------------\n");
    }
}

void searchProduct(void) {
    int id;
    printf("\nEnter product ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID input.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    for (int i = 0; i < count; i++) {
        if (products[i].id == id) {
            printf("Product found:\n");
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n", products[i].price);
            return;
        }
    }

    printf("Product not found.\n");
}

void deleteProduct(void) {
    int id;
    printf("\nEnter product ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID input.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    for (int i = 0; i < count; i++) {
        if (products[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                products[j] = products[j + 1];
            }

            count--;
            printf("Product deleted.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

int main(void) {
    int choice;

    while (1) {
        printf("\n===== Store Management System =====\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Search product\n");
        printf("4. Delete product\n");
        printf("5. Exit\n");

        printf("Your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        switch (choice) {
            case 1:
                addProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                deleteProduct();
                break;

            case 5:
                printf("Thank you for using the program!\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}