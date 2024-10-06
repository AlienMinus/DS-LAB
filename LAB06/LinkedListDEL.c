/*
LAB 6: Program 3.
Date: 07 August 2024
Purpose: WAP to delete an element at the first node
Author: Manas R. Das
*/

#include <stdio.h>   // Including standard input-output library
#include <malloc.h>  // Including memory allocation library

// Defining a node structure
struct node {
    int info;           // Defining an integer to hold data
    struct node *link;  // Defining a pointer to the next node
} *start;              // Declaring a global pointer to the start of the list

// Declaring function prototypes
void create(int data);
void delat_beg();
void display();

// Main function to drive the program
void main() {
    int c, n, m, i;  // Declaring variables
    start = NULL;    // Initializing start to NULL

    do {
        // Prompting user for choice
        printf("\nOperations:\n\t1.Create a new list\n\t2.Delete first node\n\t3.Display\n\t4.Exit\n");
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

            case 2: // Handling deletion of the first node
                delat_beg();  // Calling delat_beg function
                break;

            case 3: // Handling display
                display();  // Calling display function
                break;

            case 4: // Handling exit
                exit(0);    // Exiting the program
                break;

            default: // Handling invalid choice
                printf("Wrong Choice\n");
        }
    } while (c != 4);  // Looping until user chooses to exit
}

// Function to create a linked list
void create(int data) {
    struct node *q, *tmp;  // Declaring temporary pointers
    tmp = (struct node *)malloc(sizeof(struct node));  // Allocating memory for new node
    tmp->info = data;       // Setting data for new node
    tmp->link = NULL;       // Setting link of new node to NULL

    if (start == NULL) {    // Checking if list is empty
        start = tmp;        // Setting start to new node
    } else {
        q = start;          // Setting q to start
        while (q->link != NULL) {
            q = q->link;    // Traversing to the end of the list
        }
        q->link = tmp;      // Linking last node to new node
    }
}

// Function to delete at the first node of the linked list
void delat_beg() {
    struct node *tmp;  // Declaring temporary pointer

    if (start == NULL) {  // Checking if the list is empty
        printf("List is Empty\n");
        return;  // Exiting function
    }

    tmp = start;          // Setting tmp to start
    start = start->link;  // Moving start to the next node
    printf("Deleted element: %d\n", tmp->info);
    free(tmp);  // Freeing memory of the deleted node
}

// Function to display the linked list
void display() {
    struct node *q;   // Declaring temporary pointer

    if (start == NULL) {  // Checking if the list is empty
        printf("List is Empty\n");
        return;  // Exiting function
    }

    q = start;            // Setting q to start
    printf("The elements of the list are:\n");

    while (q != NULL) {
        printf("%d\n", q->info);  // Printing data of current node
        q = q->link;              // Traversing to the next node
    }
}

/*

OUTPUT:
Operations:
        1.Create a new list
        2.Delete first node
        3.Display
        4.Exit

Enter your choice: 1

How many nodes do you want to create: 3

Enter the elements:
1
2
3

Operations:
        1.Create a new list
        2.Delete first node
        3.Display
        4.Exit

Enter your choice: 5
Wrong Choice

Operations:
        1.Create a new list
        2.Delete first node
        3.Display
        4.Exit

Enter your choice: 2
Deleted element: 1

Operations:
        1.Create a new list
        2.Delete first node
        3.Display
        4.Exit

Enter your choice: 3
The elements of the list are:
2
3

Operations:
        1.Create a new list
        2.Delete first node
        3.Display
        4.Exit

Enter your choice: 4

*/