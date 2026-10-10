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

}
