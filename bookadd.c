
#include <stdio.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int quantity;
};

int main() {

    struct Book books[100];
    int count = 0;
    int choice;

    printf("\n--- Library Management System ---\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Search Book\n");
    printf("4. Update Book\n");
    printf("5. Delete Book\n");
    printf("6. Check Availability\n");
    printf("7. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:

            printf("Enter Book ID: ");
            scanf("%d", &books[count].id);

            printf("Enter Book Name: ");
            scanf(" %49[^\n]", books[count].title);

            printf("Enter Author Name: ");
            scanf(" %49[^\n]", books[count].author);

            printf("Enter Quantity: ");
            scanf("%d", &books[count].quantity);

            count++;

            printf("Book added successfully!\n");
            break;

        case 2:

            if(count == 0) {
                printf("No books available!\n");
            }
            else {
                for(int i = 0; i < count; i++) {

                    printf("\nBook %d\n", i + 1);
                    printf("Book ID: %d\n", books[i].id);
                    printf("Book Name: %s\n", books[i].title);
                    printf("Author: %s\n", books[i].author);
                    printf("Quantity: %d\n", books[i].quantity);
                }
            }
            break;

        // NEW FEATURE 1: SEARCH BOOK
        case 3: {

            int searchID;
            int found = 0;

            printf("Enter Book ID to search: ");
            scanf("%d", &searchID);

            for(int i = 0; i < count; i++) {

                if(books[i].id == searchID) {

                    printf("\nBook Found!\n");
                    printf("Book ID: %d\n", books[i].id);
                    printf("Book Name: %s\n", books[i].title);
                    printf("Author: %s\n", books[i].author);
                    printf("Quantity: %d\n", books[i].quantity);

                    found = 1;
                    break;
                }
            }

            if(found == 0) {
                printf("Book not found!\n");
            }

            break;
        }

        // NEW FEATURE 2: CHECK AVAILABILITY
        case 6: {

            int searchID;
            int found = 0;

            printf("Enter Book ID: ");
            scanf("%d", &searchID);

            for(int i = 0; i < count; i++) {

                if(books[i].id == searchID) {

                    found = 1;

                    if(books[i].quantity > 0) {
                        printf("Book is Available!\n");
                    }
                    else {
                        printf("Book is Not Available!\n");
                    }

                    break;
                }
            }

            if(found == 0) {
                printf("Book not found in library!\n");
            }

            break;
        }

        default:
            printf("Invalid choice or feature not implemented yet.\n");
    }

    return 0;
}
