#include <stdio.h>
#include <string.h>
#include "library.h"
#include "member.h"

Member members[MAX_MEMBERS];
int memberCount = 0;

int findMemberIndex(int id) {
    int i;
    for (i = 0; i < memberCount; i++) {
        if (members[i].active && members[i].id == id) return i;
    }
    return -1;
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
