#include<stdio.h>
#include "variables.h"
#define MAX_ATTEMPTS 3
#define MAX_TRANSACTIONS 100   

// Additional function 
int calculateDays(int date);
int validDate(int date);

void isssuebook(Book books[], int bookCount, Member members[], int memberCount, Transaction transactions[], int *transactionCount){
    int bookId,memberId,membershipSuggestion,memberExist=0,membershipControl;
    int orgtransactionDate;
    int bookIndex = -1;
    int newTransactionID;

    printf("Enter Book ID: ");
    scanf("%d",&bookId);

    for(int i = 0; i < bookCount; i++){
        if(books[i].id == bookId){
            bookIndex = i;
            break;
        }
    }

    if(bookIndex == -1){
      printf("Book doesn't exist please enter appropiate ID\n ");
    }
    else{
        printf("Enter Member ID: ");
        scanf("%d",&memberId);

        for(int i = 0; i < memberCount; i++){
            if(members[i].id == memberId){
                memberExist = 1;
                break;
            }
        }

        if (memberExist == 0)
        {
            printf("Member ID doesn't exist\n ");
            printf("We offer three memberships:\n");
            printf("1. Gold\n");
            printf("2. Silver\n");
            printf("3. Bronze\n");
            printf("If you want to become member press 1 or to continue press any key\n");
            scanf("%d",&membershipControl);
            switch (membershipControl){
            case 1:
                  printf("Enter the number of the membership you want (1-3): ");
                  scanf("%d",&membershipSuggestion);
                  if(membershipSuggestion < 1 || membershipSuggestion > 3){
                      printf("Invalid membership choice\n");
                  }
                  else{
                      memberExist=1;
                  }
                  break;
            default:
                 memberExist = 0;
                break;
            }
        }
        else{
            if(books[bookIndex].quantity <= 0){
             printf("Book already issued\n");
            }
            else if(*transactionCount >= MAX_TRANSACTIONS){
                printf("Transaction list is full\n");
            }
            else{
                printf("Enter the date today in (yyyymmdd) : \n");
                scanf("%d",&orgtransactionDate);

                if(!validDate(orgtransactionDate)){
                    printf("Invalid calendar date.\n");
                    return;
                }

                if(*transactionCount == 0){
                    newTransactionID = 1;
                }
                else{
                    newTransactionID = transactions[*transactionCount - 1].transactionID + 1;
                }

                transactions[*transactionCount].transactionID = newTransactionID;
                transactions[*transactionCount].bookID = bookId;
                transactions[*transactionCount].memberID = memberId;
                transactions[*transactionCount].issueDate = orgtransactionDate;
                transactions[*transactionCount].returnDate = 0;
                transactions[*transactionCount].returned = 0;
                (*transactionCount)++;

                books[bookIndex].quantity = books[bookIndex].quantity - 1;
                printf("Book issued successfully\n");
            }
        }
    }
}
int calculateDays(int date)
{
    int year = date / 10000;
    int month = (date / 100) % 100;
    int day = date % 100;

    int totalDays = 0;

    for (int i = 1; i < year; i++)
    {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
            totalDays += 366;
        else
            totalDays += 365;
    }

    int monthDays[] = {31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        monthDays[1] = 29;

    for (int i = 0; i < month - 1; i++)
    {
        totalDays += monthDays[i];
    }

    totalDays += day;

    return totalDays;
}

int validDate(int date)
{
    int year = date / 10000;
    int month = (date / 100) % 100;
    int day = date % 100;

    if (year < 1 || month < 1 || month > 12 || day < 1)
        return 0;

    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // last din mahine ke 

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        monthDays[1] = 29;

    if (day > monthDays[month - 1])
        return 0;

    return 1;
}

void returnBook(Book books[], int bookCount, Member members[], int memberCount, Transaction transactions[], int transactionCount)
{
    int bookID, memberID;
    int transactionDate, delayDays, delayPenalty;

    int memberID_found = 0;
    int bookID_found = 0;
    int transaction_found = 0;
    int alreadyReturned = 0;
    int bookIndex = -1;
    int transactionIndex = -1;

    for (int i = 1; i <= MAX_ATTEMPTS; i++)
    {
        printf("Enter MemberID: ");
        scanf("%d", &memberID);

        for (int j = 0; j < memberCount; j++)
        {
            if (members[j].id == memberID)
            {
                memberID_found = 1;
                break;
            }
        }

        if (memberID_found == 0)
        {
            printf("Error: Member ID doesn't match\n");
            printf("Number of attempts left: %d\n", MAX_ATTEMPTS - i);
        }
        else
        {
            break;
        }
    }

    if (memberID_found == 0)
    {
        printf("Too many tries. Returning to main menu.\n");
        return;
    }

    for (int i = 1; i <= MAX_ATTEMPTS; i++)
    {
        printf("Enter BookID: ");
        scanf("%d", &bookID);

        for (int j = 0; j < bookCount; j++)
        {
            if (books[j].id == bookID)
            {
                bookID_found = 1;
                bookIndex = j;
                break;
            }
        }

        if (bookID_found == 0)
        {
            printf("Error: Book ID doesn't match\n");
            printf("Number of attempts left: %d\n", MAX_ATTEMPTS - i);
        }
        else
        {
            break;
        }
    }

    if (bookID_found == 0)
    {
        printf("Too many tries. Returning to main menu.\n");
        return;
    }

    for (int i = 0; i < transactionCount; i++)
    {
        if (transactions[i].memberID == memberID && transactions[i].bookID == bookID)
        {
            if (transactions[i].returned == 0)
            {
                transaction_found = 1;
                transactionIndex = i;
                break;
            }
            else
            {
                alreadyReturned = 1;
            }
        }
    }

    if (transaction_found == 0)
    {
        if (alreadyReturned == 1)
        {
            printf("This book has already been returned.\n");
        }
        else
        {
            printf("No matching transaction found.\n");
        }
        return;
    }

    printf("Enter return date (YYYYMMDD): ");
    scanf("%d", &transactionDate);

    if (!validDate(transactionDate))
    {
        printf("Invalid calendar date.\n");
        return;
    }

    delayDays = calculateDays(transactionDate)
              - calculateDays(transactions[transactionIndex].issueDate);

    if (delayDays <= 0)
    {
        delayPenalty = 0;
        printf("Book returned successfully.\n");
        printf("No late fee.\n");
    }
    else if (delayDays <= 5)
    {
        delayPenalty = 50;
        printf("Late submission fee: Rs. %d\n", delayPenalty);
    }
    else if (delayDays <= 10)
    {
        delayPenalty = 100;
        printf("Late submission fee: Rs. %d\n", delayPenalty);
    }
    else
    {
        delayPenalty = 200;
        printf("Late submission fee: Rs. %d\n", delayPenalty);
    }

    transactions[transactionIndex].returnDate = transactionDate;
    transactions[transactionIndex].returned = 1;
    books[bookIndex].quantity++;

    printf("Book returned successfully.\n");
}

void displayIssuedBooks(Transaction transactions[], int totalTransactions)
{
    int found = 0;

    printf("\n---------- Currently Issued Books ----------\n");

    for (int i = 0; i < totalTransactions; i++)
    {
        if (transactions[i].returned == 0)
        {
            printf("\nTransaction ID: %d\n", transactions[i].transactionID);
            printf("Book ID: %d\n", transactions[i].bookID);
            printf("Member ID: %d\n", transactions[i].memberID);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("No books are currently issued.\n");
    }
}
