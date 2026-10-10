#include <stdio.h>
int main(){

struct Book {
    int id;
    char title[50];
    char author[50];
    int quantity;
};
  
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

switch(choice){

    case 1:
      case 1:
    printf("Enter Book ID: ");
    scanf("%d", &books[count].id);

    printf("Enter Book Name: ");
    scanf(" %99[^\n]", books[count].title);

    printf("Enter Author Name: ");
    scanf(" %99[^\n]", books[count].author);

    printf("Enter Quantity: ");
    scanf("%d", &books[count].quantity);

    count++;

    printf("Book added successfully!\n");
    break;
    
    

}
