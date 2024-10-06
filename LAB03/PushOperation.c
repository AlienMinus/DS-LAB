/*
LAB 3: Program 3.
Date: 27 July 2024
Purpose: WAP to Perform Push Operation in Stack
Author: Manas R. Das
*/
#include <stdio.h>
#include <stdlib.h>
#define maxsize 5 // Defining the Maximum Size of the Stack
// Initializing the TOP of the Stack to -1 (Indicating an Empty Stack)
int TOP = -1;
int item, stack[maxsize];
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
// Main function to Drive the program
void main()
{
    int c;
    // Loop to Continuously Prompt the User for Operations
    while (1){
        // Printing the Available Operations to Choose to Perform
        printf("Operations:\n\t1.Push\n\t2.Display\n\t3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c){
        case 1:
            // Calling the push function if the User selects 1
            push();
            break;
        case 2:
            // Calling the display function if the User selects 2
            display();
            break;
        case 3:
            // Exit form the program if the User selects 3
            exit(0);
            break;
        default:
            // Printing an Error message for Invalid Choices
            printf("Wrong Choice!\n");
        }
    }
}

/*

OUTPUT:
Operations:
        1.Push
        2.Display
        3.Exit
Enter your choice: 1
Enter the item: 1
Item pushed: 1
Operations:
        1.Push
        2.Display
        3.Exit
Enter your choice: 1
Enter the item: 7
Item pushed: 7
Operations:
        1.Push
        2.Display
        3.Exit
Enter your choice: 1
Enter the item: 4
Item pushed: 4
Operations:
        1.Push
        2.Display
        3.Exit
Enter your choice: 1
Enter the item: 6
Item pushed: 6
Operations:
        1.Push
        2.Display
        3.Exit
Enter your choice: 1
Enter the item: 3
Item pushed: 3
Operations:
        1.Push
        2.Display
        3.Exit
Enter your choice: 1

Overflow
Operations:
        1.Push
        2.Display
        3.Exit
Enter your choice: 2
The Stack elements are:
1
7
4
6
3
Operations:
        1.Push
        2.Display
        3.Exit
Enter your choice: 3

*/