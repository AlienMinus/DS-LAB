/*
LAB 11: Program 1.
Date: 31 August 2024
Purpose: WAP in C to Perform Bubblesort to sort an array of size 5
Author: Manas R. Das
*/
#include <stdio.h>
// Main function to drive the program
int main(){
    // Declaring variables: i and j as loop counters, a[5] as an array to store 5 elements, and temp as a temporary variable
    int i, j, a[5], temp;

    // Prompting the user to enter 5 elements
    printf("\nEnter 5 Elements: \n");

    // Using a for loop to iterate over the array and reading user input to store in array a
    for (i = 0; i < 5; i++)
        scanf("%d", &a[i]);

    // Starting the bubble sort algorithm to sort the array in ascending order
    for (i = 0; i < 5; i++){
        // Iterating through the array, comparing adjacent elements and swapping them if needed
        for (j = 0; j < 4 - i; j++){
            // Checking if the current element is greater than the next element
            if (a[j] > a[j + 1]){
                // Swapping the elements if the current element is greater than the next element
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
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
1
67
34
57
3

The Sorted Array is: 
1       3       34      57      67
*/
