/*
LAB 7: Program 4.
Date: 10 August 2024
Purpose: WAP to Delete an element from any position in a Singly Linked List
Author: Manas R. Das
*/
#include <stdio.h>   // Including standard input-output library
#include <stdlib.h>  // Including standard library for memory allocation functions

// Defining a node structure
struct node {
    int info;           // Defining an integer to hold data
    struct node *link;  // Defining a pointer to the next node
} *start = NULL;        // Declaring and initializing a global pointer to the start of the list

// Declaring function prototypes
void create(int data);
void del(int data);
void display();

// Main function to drive the program
int main() {
    int c, n, m, position, i;  // Declaring variables

    do {
        // Prompting user for choice
        printf("\nOperations:\n\t1. Create a new list\n\t2. Delete a specific element\n\t3. Display\n\t4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &c);  // Reading user choice

        switch (c) {
            case 1: // Handling list creation
                printf("\nHow many nodes do you want to create: ");
                scanf("%d", &n);  // Reading number of nodes to create

                printf("\nEnter the elements:\n");
                for (i = 0; i < n; i++) {  // Looping to create each node
                    scanf("%d", &m);  // Reading data for each node
                    create(m);        // Calling create function
                }
                break;

            case 2: // Handling deletion of a specific element
                printf("Enter the element for deletion\n");
                scanf("%d", &m);      // Reading data for deletion
                del(m);               // Calling del function
                break;

            case 3: // Handling display
                display();            // Calling display function
                break;

            case 4: // Handling exit
                exit(0);              // Exiting the program
                break;

            default: // Handling invalid choice
                printf("Wrong Choice\n");
        }
    } while (c != 4);  // Looping until user chooses to exit

    return 0;
}

// Creating a new node and adding it to the end of the list
void create(int data) {
    struct node *q, *tmp;  // Declaring temporary pointers
    tmp = (struct node *)malloc(sizeof(struct node));  // Allocating memory for the new node
    tmp->info = data;       // Setting data for the new node
    tmp->link = NULL;       // Setting link of the new node to NULL

    if (start == NULL) {    // Checking if the list is empty
        start = tmp;        // Setting start to the new node
    } else {
        q = start;          // Setting q to start
        while (q->link != NULL) {
            q = q->link;    // Traversing to the end of the list
        }
        q->link = tmp;      // Linking the last node to the new node
    }
}

// Deleting a node with a specific value
void del(int data) {
    struct node *tmp, *q;   // Declaring temporary pointers

    if (start == NULL) {    // Checking if the list is empty
        printf("List is Empty\n");
        return;             // Exiting function
    }

    // Handling deletion at the beginning
    if (start->info == data) {  // Checking if the first node is to be deleted
        tmp = start;            // Setting tmp to start
        start = tmp->link;      // Setting start to the next node
        free(tmp);              // Freeing memory of the deleted node
        return;                 // Exiting function
    }

    // Handling deletion at any other position
    q = start;                  // Setting q to start
    while (q->link != NULL) {
        if (q->link->info == data) {  // Checking if the node to be deleted is found
            tmp = q->link;            // Setting tmp to the node to be deleted
            q->link = tmp->link;      // Linking the previous node to the next node
            free(tmp);                // Freeing memory of the deleted node
            return;                   // Exiting function
        }
        q = q->link;              // Traversing to the next node
    }

    printf("Element %d not found\n", data);  // Printing message if the element is not found
}

// Displaying the elements in the list
void display() {
    struct node *q;   // Declaring a temporary pointer

    if (start == NULL) {  // Checking if the list is empty
        printf("List is Empty\n");
        return;           // Exiting function
    }

    q = start;            // Setting q to start
    printf("Elements of the list are:\n");

    while (q != NULL) {
        printf("%d\n", q->info);  // Printing data of the current node
        q = q->link;              // Traversing to the next node
    }
}

/*

OUTPUT:
Operations:
        1. Create a new list
        2. Delete a specific element
        3. Display
        4. Exit

Enter your choice: 1

How many nodes do you want to create: 3

Enter the elements:
1
2
3

Operations:
        1. Create a new list
        2. Delete a specific element
        3. Display
        4. Exit

Enter your choice: 3
Elements of the list are:
1
2
3

Operations:
        1. Create a new list
        2. Delete a specific element
        3. Display
        4. Exit

Enter your choice: 2
Enter the element for deletion
3

Operations:
        1. Create a new list
        2. Delete a specific element
        3. Display
        4. Exit

Enter your choice: 3
Elements of the list are:
1
2

Operations:
        1. Create a new list
        2. Delete a specific element
        3. Display
        4. Exit

Enter your choice: 5
Wrong Choice

Operations:
        1. Create a new list
        2. Delete a specific element
        3. Display
        4. Exit

Enter your choice: 4

*/