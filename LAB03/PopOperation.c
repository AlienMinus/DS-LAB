/*
LAB 3: Program 4.
Date: 27 July 2024
Purpose: WAP to perform Pop Operation in Stack
Author: Manas R. Das
*/
#include <stdio.h>
#include <stdlib.h>
#define maxsize 5 // Defining the Maximum Size of the Stack
// Initializing the TOP of the Stack to -1 (Indicating an Empty Stack)
    int TOP = -1;
int item, stack[maxsize];
// Function prototypes
void push();
void pop();
void display();
// Main function to Drive the program
void main()
{
    int c;
    // Loop to Continuously Prompt the User for Operations
    while (1){
        // Printing the Available Operations to Choose to Perform
        printf("Operations:\n\t1.Push\n\t2.Pop\n\t3.Display\n\t4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c){
        case 1:
            // Calling the push function if the User selects 1
            push();
            break;
        case 2:
            // Calling the pop function if the User selects 2
            pop();
            break;
        case 3:
            // Calling the display function if the User selects 3
            display();
            break;
        case 4:
            // Exit form the program if the User selects 4
            exit(0);
            break;
        default:
            // Printing an Error message for Invalid Choices
            printf("Wrong Choice!\n");
        }
    }
}
// Function to Push an Item onto the Stack
void push(){
    // Checking if the Stack is Full
    if (TOP == maxsize - 1){
            // If the Stack is Full, Printing Overflow Message
            printf("\nOverflow\n");
        }
    else{
        // If the Stack is not Full, Prompting the User to Enter an Item
        printf("Enter the item: ");
        scanf("%d", &item);
        // Increment in the TOP Index and Add the Item to the Stack
        TOP = TOP + 1;
        stack[TOP] = item;
        // Printing the Pushed Item
        printf("Item pushed: %d\n", item);
    }
}
// Function to Pop an Item from the Stack
void pop()
{
    // Checking if the Stack is Empty
    if (TOP == -1)
    {
        // If the Stack is Empty, Printing Underflow Message
        printf("\nUnderflow\n");
    }
    else
    {
        // Printing the Popped Item
        printf("The deleted element is %d\n", stack[TOP]);
        // Decrement in the TOP Index
        TOP = TOP - 1;
    }
}
// Function to Display the Elements of the Stack
void display(){
    int i;
    // Checking if the Stack is Empty
    if (TOP == -1){
        // If the Stack is Empty, Printing Underflow Message
        printf("\nUnderflow\n");
    }
    else{
        // If the Stack is not Empty, Printing the Etack Elements
        printf("The Stack elements are:\n");
        for (i = 0; i <= TOP; i++){
            printf("%d\n", stack[i]);
        }
    }
}

/*

OUTPUT:
Operations:
        1.Push
        2.Pop
        3.Display
        4.Exit
Enter your choice: 1
Enter the item: 1
Item pushed: 1
Operations:
        1.Push
        2.Pop
        3.Display
        4.Exit
Enter your choice: 1
Enter the item: 9
Item pushed: 9
Operations:
        1.Push
        2.Pop
        3.Display
        4.Exit
Enter your choice: 1
Enter the item: 5
Item pushed: 5
Operations:
        1.Push
        2.Pop
        3.Display
        4.Exit
Enter your choice: 1
Enter the item: 7
Item pushed: 7
Operations:
        1.Push
        2.Pop
        3.Display
        4.Exit
Enter your choice: 1
Enter the item: 3
Item pushed: 3
Operations:
        1.Push
        2.Pop
        3.Display
        4.Exit
Enter your choice: 1

Overflow
Operations:
        1.Push
        2.Pop
        3.Display
        4.Exit
Enter your choice: 3
The Stack elements are:
1
9
5
7
3
Operations:
        1.Push
        2.Pop
        3.Display
        4.Exit
Enter your choice: 2
The deleted element is 3
Operations:
        1.Push
        2.Pop
        3.Display
        4.Exit
Enter your choice: 2
The deleted element is 7
Operations:
        1.Push
        2.Pop
        3.Display
        4.Exit
Enter your choice: 2
The deleted element is 5
Operations:
        1.Push
        2.Pop
        3.Display
        4.Exit
Enter your choice: 2
The deleted element is 9
Operations:
        1.Push
        2.Pop
        3.Display
        4.Exit
Enter your choice: 2
The deleted element is 1
Operations:
        1.Push
        2.Pop
        3.Display
        4.Exit
Enter your choice: 2

Underflow
Operations:
        1.Push
        2.Pop
        3.Display
        4.Exit
Enter your choice: 3

Underflow
Operations:
        1.Push
        2.Pop
        3.Display
        4.Exit
Enter your choice: 4

*/