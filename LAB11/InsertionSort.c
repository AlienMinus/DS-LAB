/*
LAB 11: Program 2.
Date: 31 August 2024
Purpose: WAP in C to Perform Insertionsort to sort an array of size 5
Author: Manas R. Das
*/
#include <stdio.h>
// Main function to drive the program
int main(){
    // Declaring variables: i and j as loop counters, temp to store the current element, and a[5] as an array to store 5 elements
    int i, j, temp, a[5];

    // Prompting the user to enter 5 elements
    printf("\nEnter 5 Elements: \n");

    // Using a for loop to iterate over the array and reading user input to store in array a
    for (i = 0; i < 5; i++)
        scanf("%d", &a[i]);

    // Starting the insertion sort algorithm to sort the array in ascending order
    for (i = 1; i < 5; i++) {
        // Storing the current element in temp
        temp = a[i];

        // Initializing j to the previous index
        j = i - 1;

        // Moving elements that are greater than temp one position ahead
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j = j - 1;
        }

        // Inserting temp into its correct position
        a[j + 1] = temp;
    }

    // Displaying the sorted array
    printf("\nThe Sorted Array is: \n");

    // Using a for loop to print each element of the sorted array
    for (i = 0; i < 5; i++)
        printf("%d\t", a[i]);

    // Returning 0 to indicate successful execution of the program
    return 0;
}
/*
OUTPUT:
Enter 5 Elements: 
5
4
8
6
2

The Sorted Array is: 
2       4       5       6       8
*/
