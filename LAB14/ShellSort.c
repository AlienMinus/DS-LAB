/*
LAB 14: Program 1.
Date: 25 September 2024
Purpose: WAP in C to Perform Shellsort to sort an array of size 5
Author: Manas R. Das
*/
#include <stdio.h>
// Main function to drive the program
int main(){
    // Declaring variables: i, j as loop counters, temp to store the current element, gap for shell sorting, and a[5] as an array to store 5 elements
    int i, j, temp, gap, a[5];

    // Prompting the user to enter 5 elements
    printf("\nEnter 5 Elements: \n");

    // Using a for loop to iterate over the array and reading user input to store in array a
    for (i = 0; i < 5; i++)
        scanf("%d", &a[i]);

    // Starting the shell sort algorithm with an initial gap value
    for (gap = 5 / 2; gap > 0; gap /= 2) {
        // Iterating over the array elements with the current gap
        for (i = gap; i < 5; i++) {
            // Storing the current element in temp
            temp = a[i];

            // Initializing j to check elements at a gap distance
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
                // Moving elements that are greater than temp at gap distance
                a[j] = a[j - gap];
            }

            // Inserting temp into its correct position
            a[j] = temp;
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
5
4
8
6
2

The Sorted Array is: 
2       4       5       6       8
*/
