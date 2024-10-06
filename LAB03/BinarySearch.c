/*
LAB 3: Program 2.
Date: 27 July 2024
Purpose: WAP to show Binary Search
Author: Manas R. Das
*/
#include <stdio.h>
void main(){
    int i, first, last, middle, n, key, array[10];
    // Prompting the User to Enter the Number of Elements
    printf("Enter Numbers of Elements:");
    scanf("%d", &n);
    // Prompting the User to Enter the Integers
    printf("\nEnter %d Integers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    // Prompting the User to Enter the Value to Find
    printf("\nEnter Value to Find:");
    scanf("%d", &key);
    // Initializing the Binary Search Variables
    first = 0;
    last = n - 1;
    middle = (first + last) / 2;
    // Performing the Binary Search
    while (first <= last){
        if (array[middle] < key)
            first = middle + 1; // Searching in the Right-Half
        else if (array[middle] == key){
            printf("\n%d found at Location: %d.\n", key, middle + 1);
            break;
        }
        else
            last = middle - 1; // Searching in the Left-Half
        middle = (first + last) / 2; // Updating the Middle Index
    }
    // In case the Element is Not Found
    if (first > last)
        printf("\nNot Found! %d is not present in the List.\n", key);
}

/*

OUTPUT 1:
Enter Numbers of Elements:4

Enter 4 Integers:
1
5
7
3

Enter Value to Find:5

5 found at Location: 2.

OUTPUT 2:
Enter Numbers of Elements:4

Enter 4 Integers:
1
7
3
5

Enter Value to Find:6

Not Found! 6 is not present in the List.

*/