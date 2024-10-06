/*
LAB 7: Program 3.
Date: 10 August 2024
Purpose: WAP to Insert an element at any position in a Singly Linked List
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
void addafter(int data, int position);
void display();

// Main function to drive the program
int main() {
    int c, n, m, position, i;  // Declaring variables

    do {
        // Prompting user for choice
        printf("\nOperations:\n\t1. Create a new list\n\t2. Add after any position\n\t3. Display\n\t4. Exit\n");
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

            case 2: // Handling addition after a position
                printf("Enter the item\n");
                scanf("%d", &m);      // Reading data for the node
                printf("Enter the position after which to insert\n");
                scanf("%d", &position);  // Reading the position
                addafter(m, position);   // Calling addafter function
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

// Inserting a new node after a specified position
void addafter(int data, int position) {
    struct node *tmp, *q;   // Declaring temporary pointers
    int i;                  // Declaring a counter variable
    q = start;              // Setting q to start

    for (i = 0; i < position - 1; i++) {
        q = q->link;        // Traversing to the desired position
        if (q == NULL) {    // Checking if the position is out of range
            printf("There are less than %d elements\n", position);
            return;         // Exiting function if the position is invalid
        }
    }

    tmp = (struct node *)malloc(sizeof(struct node));  // Allocating memory for the new node
    tmp->info = data;       // Setting data for the new node
    tmp->link = q->link;    // Linking the new node to the next node
    q->link = tmp;          // Linking the current node to the new node
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
        2. Add after any position
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
        2. Add after any position
        3. Display
        4. Exit

Enter your choice: 3
Elements of the list are:
1
2
3

Operations:
        1. Create a new list
        2. Add after any position
        3. Display
        4. Exit

Enter your choice: 2
Enter the item
2
Enter the position after which to insert
2

Operations:
        1. Create a new list
        2. Add after any position
        3. Display
        4. Exit

Enter your choice: 3
Elements of the list are:
1
2
2
3

Operations:
        1. Create a new list
        2. Add after any position
        3. Display
        4. Exit

Enter your choice: 5
Wrong Choice

Operations:
        1. Create a new list
        2. Add after any position
        3. Display
        4. Exit

Enter your choice: 4

*/