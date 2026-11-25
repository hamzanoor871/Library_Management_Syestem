#ifndef BOOK_H
#define BOOK_H





extern Book books[MAX_BOOKS];
extern int bookCount;

int findBookIndex(int id);
int hasBook(int id);
void addBook(void);
void displayBooks(void);
void searchBook(void);
void updateBook(void);
void deleteBook(void);
void checkAvailability(void);
void bookMenu(void);


int isBookIssued(int bookID);

