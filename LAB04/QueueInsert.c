/*
LAB 4: Program 1.
Date: 31 July 2024
Purpose: WAP to insert an element into the Queue
Author: Manas R. Das
*/
#include <stdio.h>
#include <stdlib.h>
#define maxsize 5   // Defining the maximum size of the Queue
int queue[maxsize]; // Initializing the queue array
// Initializing front and rear pointers to -1 (Indicating an Empty Queue)
int front = -1, rear = -1;
// Function prototypes
void insert();
void display();

void main(){
    int c; // Variable to store User's choice
    while (1){
        // Displaying Menu Options to the User
        printf("\nOperations:\n\t1.Insert\n\t2.Display\n\t3.Exit\n");
        // Prompting Users to choose a Queue Operation
        printf("Enter your choice\n");
        scanf("%d", &c);
        // Performing the corresponding action based on User's choice
        switch (c){
        case 1:
            insert(); // Calling the insert function
            break;
        case 2:
            display(); // Calling the display function
            break;
        case 3:
            exit(0); // Exit from the program
        default:
            printf("You Entered a Wrong Choice!"); // Handling invalid choices
        }
    }
}
// Function to Insert an Element into the Queue
void insert(){
    int item; // Variable to store the item to be inserted
    // Checking for Queue Overflow
    if (rear == maxsize - 1){
        // If rear is at the last position, the Queue is full
        printf("Queue Overflow\n");
    }
    else{
        // Prompting User to Enter the New Item
        printf("The new item is :");
        scanf("%d", &item);
        // If inserting the first element, updating both front and rear
        if (front == -1)
        {
            front = 0; // Setting front to 0
        }
        // Increment in rear and inserting the item
        rear = rear + 1;
        queue[rear] = item; // Adding the item to the Queue
    }
}
// Function to display elements of the queue
void display(){
    // Checking if the queue is empty
    if (front < 0 || front > rear){
        printf("Queue is Empty"); // If front is -1 or front > rear, the Queue is empty
    }
    else
    {
        // Looping through the queue and displaying elements from front to rear
        for (int i = front; i <= rear; i++)
            printf("\n%d", queue[i]); // Printing each element
    }
}

/*

Operations:
        1.Insert
        2.Display
        3.Exit
Enter your choice
1
The new item is :1

Operations:
        1.Insert
        2.Display
        3.Exit
Enter your choice
1
The new item is :2

Operations:
        1.Insert
        2.Display
        3.Exit
Enter your choice
1
The new item is :3

Operations:
        1.Insert
        2.Display
        3.Exit
Enter your choice
1
The new item is :4

Operations:
        1.Insert
        2.Display
        3.Exit
Enter your choice
1
The new item is :5

Operations:
        1.Insert
        2.Display
        3.Exit
Enter your choice
1
Queue Overflow

Operations:
        1.Insert
        2.Display
        3.Exit
Enter your choice
2

1
2
3
4
5
Operations:
        1.Insert
        2.Display
        3.Exit
Enter your choice
3

*/