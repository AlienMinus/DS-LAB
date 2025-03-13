/*
LAB 15: Program 3.
Date: 9 November 2024
Purpose: WAP to Traverse through a Circular Linked List (Create & Display)
Author: Manas R. Das
*/
#include <stdio.h>   // Including standard input-output library
#include <stdlib.h>  // Including standard library for memory allocation

// Defining a node structure
struct node {
    int info;           // Holds data
    struct node *link;  // Pointer to the next node
} *last = NULL;         // Pointer to the last node in the list

// Function prototypes
void create(int data);
void insertAtBeginning(int data);
void insertAtPosition(int data, int position);
void insertAtEnd(int data);
void display();

int main() {
    int choice, data, position, n, m, i;

    do {
        // Menu for user choice
        printf("\nOperations:\n\t1. Create\n\t2. Insert at Beginning\n\t3. Insert at Any Position\n\t4. Insert at End\n\t5. Display\n\t6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Create or add at the end
                printf("\nHow many nodes do you want to create: ");
                scanf("%d", &n);  // Reading number of nodes to create

                printf("Enter the elements:\n");
                for (i = 0; i < n; i++) {  // Looping to create each node
                    scanf("%d", &m);  // Reading data for each node
                    create(m);        // Calling create function
                }
                break;

            case 2: // Insert at the beginning
                printf("Enter the element to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 3: // Insert at a specific position
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;

            case 4: // Insert at the end
                printf("Enter the element to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 5: // Display the list
                display();
                break;

            case 6: // Exit
                printf("Exiting program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Creates a new node or adds a node at the end
void create(int data) {
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;

    if (last == NULL) {  // If the list is empty
        tmp->link = tmp; // Points to itself to make it circular
        last = tmp;      // Sets last to the new node
    } else { // If list already has nodes, add at the end
        tmp->link = last->link;
        last->link = tmp;
        last = tmp;
    }
}

// Inserts a node at the beginning of the list
void insertAtBeginning(int data) {
    if (last == NULL) { // If list is empty, create the list
        create(data);
        return;
    }

    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = last->link; // Points to first node
    last->link = tmp;       // Last points to the new first node
}

// Inserts a node at a specified position
void insertAtPosition(int data, int position) {
    if (position < 1) {
        printf("Position should be greater than 0.\n");
        return;
    }

    struct node *tmp, *q = last->link;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;

    if (position == 1) { // Inserting at the beginning
        insertAtBeginning(data);
        return;
    }

    for (int i = 1; i < position - 1 && q != last; i++) {
        q = q->link; // Traversing to the specified position
    }

    if (q == last) { // If reached the end, insert at the end
        insertAtEnd(data);
    } else { // Insert at specified position
        tmp->link = q->link;
        q->link = tmp;
    }
}

// Inserts a node at the end of the list
void insertAtEnd(int data) {
    if (last == NULL) { // If list is empty, create the list
        create(data);
        return;
    }

    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = last->link;
    last->link = tmp;
    last = tmp;
}

// Displays the elements in the circular linked list
void display() {
    if (last == NULL) { // If list is empty
        printf("List is empty.\n");
        return;
    }

    struct node *q = last->link;
    printf("Elements of the list are:\n");

    do {
        printf("%d ", q->info);
        q = q->link;
    } while (q != last->link); // Loops back to the start

    printf("\n");
}

