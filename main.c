#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ================== STRUCTURES ==================

// Crew Node
typedef struct Crew {
    int id;
    char name[50];
    struct Crew* next;
    struct AdjList* adj;
} Crew;

// Adjacency List (Edge)
typedef struct AdjList {
    struct Crew* dest;
    struct AdjList* next;
} AdjList;

// Head of crew list
Crew* head = NULL;


// ================== UTILITY FUNCTIONS ==================

// Find Crew by ID
Crew* findCrew(int id) {
    Crew* temp = head;
    while (temp != NULL) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}


// ================== CRUD OPERATIONS ==================

// 🔹 CREATE → Add Crew
void addCrew() {
    Crew* newCrew = (Crew*)malloc(sizeof(Crew));

    printf("\nEnter Crew ID   : ");
    scanf("%d", &newCrew->id);

    printf("Enter Crew Name : ");
    scanf("%s", newCrew->name);

    newCrew->adj = NULL;
    newCrew->next = head;
    head = newCrew;

    printf("✅ Crew Added Successfully!\n");
}


// 🔹 READ → Display Graph
void display() {
    if (head == NULL) {
        printf("\n⚠ No Crew Data Available\n");
        return;
    }

    Crew* temp = head;

    printf("\n--- Crew Assignment Graph ---\n");

    while (temp != NULL) {
        printf("Crew %d (%s) ➝ ", temp->id, temp->name);

        AdjList* adj = temp->adj;
        while (adj != NULL) {
            printf("%d ", adj->dest->id);
            adj = adj->next;
        }

        printf("\n");
        temp = temp->next;
    }
}


// 🔹 UPDATE → Modify Crew
void updateCrew() {
    int id;
    printf("\nEnter Crew ID to Update: ");
    scanf("%d", &id);

    Crew* temp = findCrew(id);

    if (temp == NULL) {
        printf("❌ Crew Not Found!\n");
        return;
    }

    printf("Enter New Name: ");
    scanf("%s", temp->name);

    printf("✅ Crew Updated Successfully!\n");
}


// 🔹 DELETE → Remove Crew
void deleteCrew() {
    int id;
    printf("\nEnter Crew ID to Delete: ");
    scanf("%d", &id);

    Crew *temp = head, *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("❌ Crew Not Found!\n");
        return;
    }

    // Remove from main list
    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    // Free adjacency list
    AdjList* adj = temp->adj;
    while (adj != NULL) {
        AdjList* t = adj;
        adj = adj->next;
        free(t);
    }

    free(temp);

    printf("✅ Crew Deleted Successfully!\n");
}


// 🔹 SEARCH → Find Crew
void searchCrew() {
    int id;
    printf("\nEnter Crew ID to Search: ");
    scanf("%d", &id);

    Crew* found = findCrew(id);

    if (found)
        printf("🔍 Found → ID: %d | Name: %s\n", found->id, found->name);
    else
        printf("❌ Crew Not Found!\n");
}


// ================== GRAPH OPERATION ==================

// Add Assignment (Edge)
void addAssignment() {
    int id1, id2;

    printf("\nEnter Source Crew ID      : ");
    scanf("%d", &id1);

    printf("Enter Destination Crew ID : ");
    scanf("%d", &id2);

    Crew* c1 = findCrew(id1);
    Crew* c2 = findCrew(id2);

    if (c1 == NULL || c2 == NULL) {
        printf("❌ Invalid Crew ID(s)\n");
        return;
    }

    AdjList* newEdge = (AdjList*)malloc(sizeof(AdjList));
    newEdge->dest = c2;
    newEdge->next = c1->adj;
    c1->adj = newEdge;

    printf("✅ Assignment Added!\n");
}


// ================== MAIN MENU ==================

int main() {
    int choice;

    while (1) {
        printf("\n====================================\n");
        printf(" ✈️ AIRLINE CREW MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Crew (Create)\n");
        printf("2. Delete Crew\n");
        printf("3. Update Crew\n");
        printf("4. Search Crew\n");
        printf("5. Display Graph\n");
        printf("6. Add Assignment\n");
        printf("7. Exit\n");
        printf("====================================\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCrew(); break;
            case 2: deleteCrew(); break;
            case 3: updateCrew(); break;
            case 4: searchCrew(); break;
            case 5: display(); break;
            case 6: addAssignment(); break;
            case 7: printf("👋 Exiting...\n"); exit(0);
            default: printf("❌ Invalid Choice!\n");
        }
    }

    return 0;
}
