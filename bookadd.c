

#include <stdio.h>
#include <string.h>
#include "book.h"

Book books[MAX_BOOKS];
int bookCount = 0;

int findBookIndex(int id)
{
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == id)
            return i;
    }

    return -1;
}

int hasBook(int id)
{
    return findBookIndex(id) != -1;
}

void addBook(void)
{
    Book b;

    if (bookCount >= MAX_BOOKS)
    {
        printf("Book storage is full.\n");
        return;
    }

    printf("Enter Book ID: ");
    if (scanf("%d", &b.id) != 1)
    {
        printf("Invalid ID.\n");
        while (getchar() != '\n');
        return;
    }

    if (hasBook(b.id))
    {
        printf("This Book ID already exists.\n");
        return;
    }

    getchar();

    printf("Enter Book Name: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    printf("Enter Quantity: ");
    if (scanf("%d", &b.quantity) != 1 || b.quantity < 0)
    {
        printf("Invalid quantity.\n");
        while (getchar() != '\n');
        return;
    }

    books[bookCount] = b;
    bookCount++;

    printf("Book added successfully.\n");
}

void displayBooks(void)
{
    if (bookCount == 0)
    {
        printf("No books available.\n");
        return;
    }

    printf("\n--- BOOK LIST ---\n");

    for (int i = 0; i < bookCount; i++)
    {
        printf("\nBook ID: %d\n", books[i].id);
        printf("Book Name: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Quantity: %d\n", books[i].quantity);
    }
}

void searchBook(void)
{
    int id, index;

    printf("Enter Book ID to search: ");
    if (scanf("%d", &id) != 1)
    {
        printf("Invalid ID.\n");
        while (getchar() != '\n');
        return;
    }

    index = findBookIndex(id);

    if (index == -1)
    {
        printf("Book not found.\n");
        return;
    }

    printf("\nBook Found!\n");
    printf("Book ID: %d\n", books[index].id);
    printf("Book Name: %s\n", books[index].title);
    printf("Author: %s\n", books[index].author);
    printf("Quantity: %d\n", books[index].quantity);
}

void updateBook(void)
{
    int id, index;

    printf("Enter Book ID to update: ");
    if (scanf("%d", &id) != 1)
    {
        printf("Invalid ID.\n");
        while (getchar() != '\n');
        return;
    }

    index = findBookIndex(id);

    if (index == -1)
    {
        printf("Book not found.\n");
        return;
    }

    getchar();

    printf("Enter new Book Name: ");
    fgets(books[index].title, sizeof(books[index].title), stdin);
    books[index].title[strcspn(books[index].title, "\n")] = '\0';

    printf("Enter new Author Name: ");
    fgets(books[index].author, sizeof(books[index].author), stdin);
    books[index].author[strcspn(books[index].author, "\n")] = '\0';

    printf("Enter new Quantity: ");
    if (scanf("%d", &books[index].quantity) != 1
        || books[index].quantity < 0)
    {
        printf("Invalid quantity.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Book updated successfully.\n");
}

void deleteBook(void)
{
    int id, index;

    printf("Enter Book ID to delete: ");
    if (scanf("%d", &id) != 1)
    {
        printf("Invalid ID.\n");
        while (getchar() != '\n');
        return;
    }

    index = findBookIndex(id);

    if (index == -1)
    {
        printf("Book not found.\n");
        return;
    }

    if (isBookIssued(id))
    {
        printf("This book has active issued transactions.\n");
        printf("Return the book before deleting it.\n");
        return;
    }

    for (int i = index; i < bookCount - 1; i++)
    {
        books[i] = books[i + 1];
    }

    bookCount--;

    printf("Book deleted successfully.\n");
}

void checkAvailability(void)
{
    int id, index;

    printf("Enter Book ID: ");
    if (scanf("%d", &id) != 1)
    {
        printf("Invalid ID.\n");
        while (getchar() != '\n');
        return;
    }

    index = findBookIndex(id);

    if (index == -1)
    {
        printf("Book not found.\n");
        return;
    }

    if (books[index].quantity > 0)
    {
        printf("Book is available.\n");
        printf("Available copies: %d\n", books[index].quantity);
    }
    else
    {
        printf("Book is currently unavailable.\n");
    }
}


void bookMenu(void)
{
    int choice;

    do
    {
        printf("\n===== BOOK MANAGEMENT =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Check Availability\n");
        printf("7. Back to Main Menu\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice)
        {
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
                updateBook();
                break;

            case 5:
                deleteBook();
                break;

            case 6:
                checkAvailability();
                break;

            case 7:
                printf("Returning to Main Menu...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 7);
}
