/*
LAB 5: Program 1.
Date: 03 August 2024
Purpose: WAP to insert an element into the Circular Queue
Author: Manas R. Das
*/
#include <stdio.h>
#include <stdlib.h>
#define maxsize 5  // Defining the maximum size of the Queue
int queue[maxsize]; // Initializing the queue array
// Initializing front and rear pointers to -1 (Indicating an Empty Queue)
int front = -1, rear = -1;
// Function Prototype
void insert();
void display();
// Main function to Drive the Program
void main(){
    int c;
    while (1){
        // Displaying Menu options
        printf("\nOperations:\n\t1.Insert\\n\t2.Display\n\t3.Exit\n");
        // Prompting Users to choose a Queue Operation
        printf("\nEnter your choice: ");
        scanf("%d", &c);
        switch (c){
        // Performing the corresponding action based on User's choice
        case 1:
            // Calling the insert function
            insert();
            break;
        case 2:
            // Calling the display function
            display();
            break;
        case 3:
            // Exiting the program
            exit(0);
        default:
            // Handling invalid input
            printf("\nYou Entered a Wrong Choice!\n");
        }
    }
}
// Function to Insert an Element into the Queue
void insert(){
    int item; // Variable to store the item to be inserted
    // Checking for queue overflow
    if ((rear + 1) % maxsize == front){
        // If rear is at the last position, the Queue is full
        printf("\nQueue Overflow\n");
    }
    else{
        // Prompting User to Enter the New Item
        printf("\nEnter the inserted element: ");
        scanf("%d", &item);
        // If inserting the first element, updating both front and rear
        if (front == -1){
            front = 0; // Setting front to 0
            rear = 0;
        }
        else{
            // Moving the rear to the next position
            rear = (rear + 1) % maxsize;
        }
        // Inserting the element in the queue
        queue[rear] = item;
    }
}
// Function to display elements of the queue
void display(){
    // Checking if the queue is empty
    if (front == -1){
        printf("\nQueue is Empty\n");
    }
    else{
        // Initializing the iterator
        int i = front;
        // Printing the queue elements
        printf("\nQueue elements are:\n");
        while (1){
            printf("%d\n", queue[i]);
            // Breaking the loop when the rear is reached
            if (i == rear){
                break;
            }
            // Moving to the next position
            i = (i + 1) % maxsize;
        }
    }
}

/*

OUTPUT:
Operations:
        1.Insert
        2.Display
        3.Exit

Enter your choice: 1

Enter the inserted element: 1

Operations:
        1.Insert
        2.Display
        3.Exit

Enter your choice: 1

Enter the inserted element: 2

Operations:
        1.Insert
        2.Display
        3.Exit

Enter your choice: 1

Enter the inserted element: 3

Operations:
        1.Insert
        2.Display
        3.Exit

Enter your choice: 1

Enter the inserted element: 4

Operations:
        1.Insert
        2.Display
        3.Exit

Enter your choice: 1

Enter the inserted element: 5

Operations:
        1.Insert
        2.Display
        3.Exit

Enter your choice: 1

Queue Overflow

Operations:
        1.Insert
        2.Display
        3.Exit

Enter your choice: 3

Queue elements are:
1
2
3
4
5

Operations:
        1.Insert
        2.Display
        3.Exit

Enter your choice: 4


*/