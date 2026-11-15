#include<stdio.h>
#define MAX_ATTEMPTS 3
void isssuebook(){
    int bookId,memberId,membershipSuggestion,memberExist=0,membershipControl,bookStatus,bookCopies;
    int orgtransactionDate;
    const existingBooks;

    if(bookId != existingBooks){
      printf("Book doesn't exist please enter appropiate ID\n ");
    }
    else{
        if (memberId != memberExist)
        {
            printf("Member ID doesn't exist\n ");
            printf("If you want to become member press 1 or to continue press any key\n");
            scanf("%d",&membershipControl);
            switch (membershipControl){
            case 1:
                  memberExist=1;
            default:
                 memberExist = 0;
                break;
            }
        }
        else{
            if(bookStatus){
             printf("Book already issued\n");
            }
            else{
                printtf("Book issued successfully\n");
                bookStatus=1;
                bookCopies = bookCopies - 1;
                printf("Enter the date today in (yymmdd) : \n");
                scanf("%d",&orgtransactionDate);
                

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

void returnBook()
{
    int transactionID, bookID, memberID;
    int transactionDate, bookCopies, delayDays, delayPenalty;

    const int existedID;
    const int existedbookID;
    const int orgbookTransacationDate;

    int memberID_found = 0;
    int bookID_found = 0;
    int transaction_found = 0;
    int returned = 0;

    for (int i = 1; i <= MAX_ATTEMPTS; i++)
    {
        printf("Enter MemberID: ");
        scanf("%d", &memberID);

        if (memberID != existedID)
        {
            printf("Error: Member ID doesn't match\n");
            printf("Number of attempts left: %d\n", MAX_ATTEMPTS - i);
        }
        else
        {
            memberID_found = 1;
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

        if (bookID != existedbookID)
        {
            printf("Error: Book ID doesn't match\n");
            printf("Number of attempts left: %d\n", MAX_ATTEMPTS - i);
        }
        else
        {
            bookID_found = 1;
            break;
        }
    }

    if (bookID_found == 0)
    {
        printf("Too many tries. Returning to main menu.\n");
        return;
    }

    if (memberID == existedID && bookID == existedbookID)
    {
        transaction_found = 1;
    }

    if (transaction_found == 0)
    {
        printf("No matching transaction found.\n");
        return;
    }

    if (returned == 1)
    {
        printf("This book has already been returned.\n");
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
              - calculateDays(orgbookTransacationDate);

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

    returned = 1;
    bookCopies++;

    printf("Book returned successfully.\n");
}

void displayIssuedBooks()
{
    int transactionID[] = {101, 102, 103, 104};                     //temporary arrays later through file handling things will be stored in arrays
    int bookID[] = {501, 502, 503, 504};
    int memberID[] = {1001, 1002, 1003, 1004};
    int returned[] = {0, 1, 0, 1};

    int totalTransactions = 4;
    int found = 0;

    printf("\n---------- Currently Issued Books ----------\n");

    for (int i = 0; i < totalTransactions; i++)
    {
        if (returned[i] == 0)
        {
            printf("\nTransaction ID: %d\n", transactionID[i]);
            printf("Book ID: %d\n", bookID[i]);
            printf("Member ID: %d\n", memberID[i]);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("No books are currently issued.\n");
    }
}
