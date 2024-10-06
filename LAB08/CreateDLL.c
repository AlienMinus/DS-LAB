/*
LAB 8: Program 1.
Date: 21 August 2024
Purpose: WAP to create a Double Linked List
Author: Manas R. Das
*/
#include <stdio.h>      // Including the standard input-output header file
#include <stdlib.h>     // Including the standard library header file for dynamic memory allocation

// Function prototype
void create(int);       // Declaring the create function prototype

// Defining a structure for the doubly linked list node
struct node {
    int data;           // Declaring an integer data to store the value of the node
    struct node *next;  // Declaring a pointer to the next node in the list
    struct node *prev;  // Declaring a pointer to the previous node in the list
};

// Defining a global pointer to the head of the list
struct node *head;

void main() {
    int n;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);   // Reading the number of nodes to create
    create(n);          // Calling the create function with n nodes
}

// Function to create a doubly linked list with n nodes
void create(int n) {
    struct node *newNode, *temp;
    int item, i;

    if (n <= 0) {          // Checking if the number of nodes is valid
        printf("\nInvalid number of nodes.");
        return;
    }

    printf("\nEnter the data for node 1: ");
    scanf("%d", &item);    // Reading the data for the first node

    // Creating the head node
    head = (struct node *)malloc(sizeof(struct node));  // Allocating memory for the head node
    if (head == NULL) {     // Checking if memory allocation failed
        printf("\nMemory allocation failed");
        return;
    }
    head->data = item;      // Assigning the data to the head node
    head->next = NULL;      // Setting the next pointer of the head node to NULL
    head->prev = NULL;      // Setting the previous pointer of the head node to NULL
    temp = head;            // Setting temp to point to the head node

    // Loop to create the rest of the nodes
    for (i = 2; i <= n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));  // Allocating memory for a new node
        if (newNode == NULL) {    // Checking if memory allocation failed
            printf("\nMemory allocation failed");
            return;
        }
        printf("Enter the data for node %d: ", i);
        scanf("%d", &item);    // Reading the data for the current node

        newNode->data = item;   // Assigning data to the new node
        newNode->next = NULL;   // Setting the next pointer of the new node to NULL
        newNode->prev = temp;   // Setting the previous pointer of the new node to point to temp (the last node)
        temp->next = newNode;   // Linking the last node (temp) to the new node
        temp = newNode;         // Updating temp to point to the new node
    }

    printf("\nDoubly linked list created successfully.\n");
}

/*
OUTPUT:
Enter the number of nodes: 3

Enter the data for node 1: 1
Enter the data for node 2: 2
Enter the data for node 3: 3

Doubly linked list created successfully.
 */