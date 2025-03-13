/*
LAB 15: Program 1.
Date: 9 November 2024
Purpose: WAP to Traverse through a Circular Linked List (Create & Display)
Author: Manas R. Das
*/
#include <stdio.h>   // Including standard input-output library
#include <stdlib.h>  // Including standard library for memory allocation

// Defining a node structure
struct node {
    int info;           // Defining an integer to hold data
    struct node *link;  // Defining a pointer to the next node
} *last;                // Declaring a global pointer to the last node in the list

// Declaring function prototypes
void create(int data);
void display();

// Main function to drive the program
int main() {
    int c, n, m, i;  // Declaring variables
    last = NULL;     // Initializing last to NULL

    do {
        // Prompting user for choice
        printf("\nOperations:\n\t1. Create a new list\n\t2. Display\n\t3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);  // Reading user choice

        switch (c) {
            case 1: // Handling list creation
                printf("\nHow many nodes do you want to create: ");
                scanf("%d", &n);  // Reading number of nodes to create

                printf("Enter the elements:\n");
                for (i = 0; i < n; i++) {  // Looping to create each node
                    scanf("%d", &m);  // Reading data for each node
                    create(m);        // Calling create function
                }
                break;

            case 2: // Handling display
                display();  // Calling display function
                break;

            case 3: // Handling exit
                exit(0);    // Exiting the program
                break;

            default: // Handling invalid choice
                printf("Wrong Choice\n");
        }
    } while (c != 3);  // Looping until user chooses to exit
}

// Function to create a circular linked list
void create(int data) {
    struct node *tmp = (struct node *)malloc(sizeof(struct node));  // Allocating memory for new node
    tmp->info = data;    // Setting data for new node

    if (last == NULL) {  // Checking if list is empty
        last = tmp;      // Setting last to new node
        tmp->link = last; // Making the list circular by linking to itself
    } else {
        tmp->link = last->link;  // New node points to the first node
        last->link = tmp;        // Old last node points to new node
        last = tmp;              // Updating last to the new node
    }
}

// Function to display a circular linked list
void display() {
    if (last == NULL) {  // Checking if the list is empty
        printf("List is Empty\n");
        return;          // Exiting function
    }

    struct node *q = last->link;  // Setting q to first node
    printf("The elements of the list are:\n");

    do {
        printf("%d\n", q->info);  // Printing data of current node
        q = q->link;              // Traversing to the next node
    } while (q != last->link);    // Looping until we return to the starting node
}

/*
OUTPUT:
Operations:
        1. Create a new list
        2. Display
        3. Exit
Enter your choice: 4
Wrong Choice

Operations:
        1. Create a new list
        2. Display
        3. Exit
Enter your choice: 1

How many nodes do you want to create: 3
Enter the elements:
1
2
3

Operations:
        1. Create a new list
        2. Display
        3. Exit
Enter your choice: 2
The elements of the list are:
1
2
3

Operations:
        1. Create a new list
        2. Display
        3. Exit
Enter your choice: 3
*/