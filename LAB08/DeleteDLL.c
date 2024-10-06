/*
LAB 8: Program 4.
Date: 21 August 2024
Purpose: WAP to delete at beginnning of a Double Linked List
Author: Manas R. Das
*/
#include <stdio.h>      // Including the standard input-output header file
#include <stdlib.h>     // Including the standard library header file for dynamic memory allocation

// Function prototypes
void create(int);       // Declaring the create function prototype
void display();         // Declaring the display function prototype
void delbeg();          // Declaring the delete at beginning function prototype

// Defining a structure for the doubly linked list node
struct node {
    int data;           // Declaring an integer data to store the value of the node
    struct node *next;  // Declaring a pointer to the next node in the list
    struct node *prev;  // Declaring a pointer to the previous node in the list
};

// Defining a global pointer to the head of the list
struct node *head;

void main() {
    int c, p, item, n;
    
    // Beginning an infinite loop for menu-driven options
    do {
        // Displaying menu options
        printf("\nOperation:\n\t1.Creation\n\t2.Traverse\n\t3.Delete at Beginning\n\t4.Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &c);   // Reading the user's choice
        
        switch (c) {       // Starting a switch-case block based on user choice
        case 1:            // If the user selects 1 (Creation)
            printf("\nEnter the number of nodes: ");
            scanf("%d", &n);   // Reading the number of nodes to create
            create(n);          // Calling the create function with n nodes
            break;
        case 2:            // If the user selects 2 (Traverse)
            display();     // Calling the display function to traverse the list
            break;
        case 3:            // If the user selects 4 (Delete at Beginning)
            delbeg();      // Calling the delete at beginning function
            break;
        case 4:            // If the user selects 4 (Exit)
            exit(0);       // Exiting the program
            break;
        default:           // If the user enters an invalid choice
            printf("\nPlease Enter a Valid choice!\n");
        }
    } while (c != 4);      // Looping back to the menu until the user selects Exit
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

// Function to traverse and display the list
void display() {
    struct node *ptr = head;  // Initializing ptr to the head of the list
    if (head == NULL) {       // Checking if the list is empty
        printf("\nEmpty List");
    }
    else {
        while (ptr != NULL) {  // Looping through the list until the end
            printf("%d\n", ptr->data);  // Printing the data of the current node
            ptr = ptr->next;            // Moving to the next node
        }
    }
}

// Function to delete the first node of the list
void delbeg() {
    struct node *ptr;
    if (head == NULL) {  // Checking if the list is empty
        printf("\nUNDERFLOW");
    }
    else if (head->next == NULL) {  // Checking if there is only one node in the list
        head = NULL;    // Setting the head to NULL, making the list empty
        free(head);     // Freeing the memory of the single node
        printf("\nNode Deleted\n");
    }
    else {
        ptr = head;     // Setting ptr to the current head
        head = head->next;  // Moving the head to the next node
        head->prev = NULL;  // Setting the previous pointer of the new head to NULL
        free(ptr);      // Freeing the memory of the old head node
        printf("\nNode Deleted.\n");
    }
}

/*
OUTPUT:
Operation:
        1.Creation
        2.Traverse
        3.Delete at Beginning
        4.Exit

Enter Your Choice: 2

Empty List
Operation:
        1.Creation
        2.Traverse
        3.Delete at Beginning
        4.Exit

Enter Your Choice: 1

Enter the number of nodes: 3

Enter the data for node 1: 1
Enter the data for node 2: 2
Enter the data for node 3: 3

Doubly linked list created successfully.

Operation:
        1.Creation
        2.Traverse
        3.Delete at Beginning
        4.Exit

Enter Your Choice: 2
1
2
3

Operation:
        1.Creation
        2.Traverse
        3.Delete at Beginning
        4.Exit

Enter Your Choice: 3

Node Deleted.

Operation:
        1.Creation
        2.Traverse
        3.Delete at Beginning
        4.Exit

Enter Your Choice: 2
2
3

Operation:
        1.Creation
        2.Traverse
        3.Delete at Beginning
        4.Exit

Enter Your Choice: 4
*/