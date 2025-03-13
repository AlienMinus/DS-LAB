/*
LAB 15: Program 2.
Date: 9 November 2024
Purpose: WAP to Traverse through a Circular Linked List (Create, Insertion at Beginning, Insertion at End, Display)
Author: Manas R. Das
*/
#include <stdio.h>   // Including standard input-output library
#include <stdlib.h>  // Including standard library for memory allocation functions

// Defining a node structure
struct node {
    int info;           // Defining an integer to hold data
    struct node *link;  // Defining a pointer to the next node
} *last = NULL;        // Declaring and initializing a global pointer to the last node of the list

// Declaring function prototypes
void create(int data);
void insert_at_beg(int data);
void insert_at_end(int data);
void display();

int main() {
    int choice, n, data, i;  // Declaring variables

    do {
        // Prompting user for choice
        printf("\nOperations:\n\t1. Create a new list\n\t2. Insert at beginning\n\t3. Insert at end\n\t4. Display\n\t5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);  // Reading user choice

        switch (choice) {
            case 1: // Handling list creation
                printf("\nHow many nodes do you want to create: ");
                scanf("%d", &n);  // Reading number of nodes to create

                printf("\nEnter the elements:\n");
                for (i = 0; i < n; i++) {  // Looping to create each node
                    scanf("%d", &data);  // Reading data for each node
                    create(data);        // Calling create function
                }
                break;

            case 2: // Handling insertion at the beginning
                printf("\nEnter the item to insert at the beginning: ");
                scanf("%d", &data);   // Reading data for the new node
                insert_at_beg(data);      // Calling insert_at_beg function
                break;

            case 3: // Handling insertition at the end
                printf("\nEnter the item to insert at the end: ");
                scanf("%d", &data);   // Reading data for the new node
                insert_at_end(data);     // Calling insert_at_end function
                break;

            case 4: // Handling display
                display();            // Calling display function
                break;

            case 5: // Handling exit
                printf("Exiting program.\n");
                exit(0);              // Exiting the program
                break;

            default: // Handling invalid choice
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);  // Looping until user chooses to exit

    return 0;
}

// Function to create a circular linked list with a single node
void create(int data) {
    struct node *tmp = (struct node *)malloc(sizeof(struct node));  // Allocating memory for new node
    tmp->info = data;       // Setting data for new node
    if (last == NULL) {     // Checking if list is empty
        last = tmp;         // Setting last to new node
        last->link = last;  // Pointing new node to itself to make it circular
    } else {
        tmp->link = last->link;  // Pointing new node to first node
        last->link = tmp;        // Updating last node to point to new node
        last = tmp;              // Updating last pointer to new node
    }
}

// Function to insert a node at the beginning of a circular linked list
void insert_at_beg(int data) {
    if (last == NULL) {        // If list is empty, create the first node
        create(data);
    } else {
        struct node *tmp = (struct node *)malloc(sizeof(struct node));  // Allocating memory for new node
        tmp->info = data;       // Setting data for new node
        tmp->link = last->link; // Pointing new node to first node
        last->link = tmp;       // Updating last node to point to new node (new beginning node)
    }
}

// Function to insert a node at the end of a circular linked list
void insert_at_end(int data) {
    if (last == NULL) {         // If list is empty, create the first node
        create(data);
    } else {
        struct node *tmp = (struct node *)malloc(sizeof(struct node));  // Allocating memory for new node
        tmp->info = data;       // Setting data for new node
        tmp->link = last->link; // Pointing new node to first node
        last->link = tmp;       // Updating last node to point to new node
        last = tmp;             // Setting last to new node
    }
}

// Function to display the elements of the circular linked list
void display() {
    if (last == NULL) {  // Checking if the list is empty
        printf("List is Empty\n");
        return;          // Exiting function
    }

    struct node *tmp = last->link;  // Starting from the first node
    printf("Elements of the list are:\n");
    do {
        printf("%d ", tmp->info);  // Printing data of current node
        tmp = tmp->link;           // Moving to the next node
    } while (tmp != last->link);   // Looping until we come back to the first node
    printf("\n");
}
/*
OUTPUT:
Operations:
        1. Create a new list
        2. Insert at beginning
        3. Insert at end
        4. Display
        5. Exit

Enter your choice: 1

How many nodes do you want to create: 3

Enter the elements:
1
2
3

Operations:
        1. Create a new list
        2. Insert at beginning
        3. Insert at end
        4. Display
        5. Exit

Enter your choice: 4
Elements of the list are:
1 2 3

Operations:
        1. Create a new list
        2. Insert at beginning
        3. Insert at end
        4. Display
        5. Exit

Enter your choice: 2

Enter the item to insert at the beginning: 4

Operations:
        1. Create a new list
        2. Insert at beginning
        3. Insert at end
        4. Display
        5. Exit

Enter your choice: 4
Elements of the list are:
4 1 2 3

Operations:
        1. Create a new list
        2. Insert at beginning
        3. Insert at end
        4. Display
        5. Exit

Enter your choice: 3

Enter the item to insert at the end: 5

Operations:
        1. Create a new list
        2. Insert at beginning
        3. Insert at end
        4. Display
        5. Exit

Enter your choice: 4
Elements of the list are:
4 1 2 3 5

Operations:
        1. Create a new list
        2. Insert at beginning
        3. Insert at end
        4. Display
        5. Exit

Enter your choice: 6

Invalid choice. Please try again.

Operations:
        1. Create a new list
        2. Insert at beginning
        3. Insert at end
        4. Display
        5. Exit

Enter your choice: 5
Exiting program.

*/