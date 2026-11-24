#include <stdio.h>
#include <string.h>
#define MAX_MEMBERS 100

typedef struct
{
    int id;
    char name[50];
    char contact[20];
    int active;
} Member;
int hasIssuedBooks(int id);
Member members[MAX_MEMBERS];
int memberCount = 0;

int findMemberIndex(int id) {
    int i;
    for (i = 0; i < memberCount; i++) {
        if (members[i].active && members[i].id == id) return i;
    }
    return -1;
}

int hasMember(int id)
{
    return findMemberIndex(id) != -1;
}

static void readLine(char text[], int size) {
    if (fgets(text, size, stdin) != NULL) {
        text[strcspn(text, "\n")] = '\0';
    }
}

void addMember(void) {
    Member m;
    if (memberCount >= MAX_MEMBERS) {
        printf("Member storage is full.\n");
        return;
    }

    printf("Enter member ID: ");
    if (scanf("%d", &m.id) != 1) { getchar(); printf("Invalid ID.\n"); return; }
    getchar();

    if (findMemberIndex(m.id) != -1) {
        printf("This member ID already exists.\n");
        return;
    }

    printf("Enter member name: ");
    readLine(m.name, sizeof(m.name));
    printf("Enter contact: ");
    readLine(m.contact, sizeof(m.contact));

    m.active = 1;
    members[memberCount++] = m;
    printf("Member registered successfully.\n");
}

void viewMembers(void) {
    int i, found = 0;
    printf("\n--- MEMBER LIST ---\n");
    for (i = 0; i < memberCount; i++) {
        if (members[i].active) {
            printf("ID: %d | Name: %s | Contact: %s\n",
                   members[i].id, members[i].name, members[i].contact);
            found = 1;
        }
    }
    if (!found) printf("No members found.\n");
}

void searchMember(void) {
    int id, index;
    printf("Enter member ID to search: ");
    if (scanf("%d", &id) != 1) { getchar(); printf("Invalid ID.\n"); return; }
    getchar();
    index = findMemberIndex(id);
    if (index == -1) printf("Member not found.\n");
    else printf("ID: %d | Name: %s | Contact: %s\n",
                members[index].id, members[index].name, members[index].contact);
}
void updateMember(void) {
    int id, index;

    printf("Enter member ID to update: ");

    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        return;
    }
    getchar();

    index = findMemberIndex(id);

    if (index == -1) {
        printf("Member not found.\n");
        return;
    }

    printf("Enter new member name: ");
    readLine(members[index].name,
             sizeof(members[index].name));

    printf("Enter new contact: ");
    readLine(members[index].contact,
             sizeof(members[index].contact));

    printf("Member updated successfully.\n");
}
void deleteMember(void) {
    int id, index;

    printf("Enter member ID to delete: ");

    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        return;
    }
    getchar();

    index = findMemberIndex(id);

    if (index == -1) {
        printf("Member not found.\n");
        return;
    }

   if (hasIssuedBooks(id))
{
    printf("Please return issued book before deleting member.\n");
    return;
}

    members[index].active = 0;

    printf("Member deleted successfully.\n");
}

void memberMenu()
{
    int choice;

    do
    {
        printf("\n===== MEMBER MANAGEMENT =====\n");
        printf("1. Add Member\n");
        printf("2. View Members\n");
        printf("3. Search Member\n");
        printf("4. Update Member\n");
        printf("5. Delete Member\n");
        printf("6. Back to Main Menu\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addMember();
                break;

            case 2:
                viewMembers();
                break;

            case 3:
                searchMember();
                break;

            case 4:
                updateMember();
                break;

            case 5:
                deleteMember();
                break;

            case 6:
                printf("Returning to Main Menu...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);
}
