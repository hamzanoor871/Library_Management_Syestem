#include<stdio.h>
void isssuebook(){
    int bookId,memberId,membershipSuggestion,memberExist=0,membershipControl,bookStatus,bookCopies;
    const existingBooks;

    if(bookId != existingBooks){
      printf("Book doesn't exist please enter appropiate ID ");
    }
    else{
        if (memberId != memberExist)
        {
            printf("Member ID doesn't exist ");
            printf("If you want to become member press 1 or to continue press any key");
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
             printf("Book already issued");
            }
            else{
                printtf("Book issued successfully");
                bookStatus=1;
                bookCopies = bookCopies - 1;
                

            }
        }
        
    }

}