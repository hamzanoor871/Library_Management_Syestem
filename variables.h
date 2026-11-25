#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct {
    int id;
    char title[50];
    char author[50];
    int quantity;
    float price;
} Book;

typedef struct {
    int id;
    char name[100];
    char contact[20];
    int active;
} Member;

typedef struct {
    int transactionID;
    int bookID;
    int memberID;
    int issueDate;
    int returnDate;
    int returned;
} Transaction;

#endif