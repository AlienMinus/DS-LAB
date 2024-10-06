/*
LAB 13: Program 1.
Date: 21 September 2024
Purpose: WAP in C to Perform Selection Sort to sort an array of size 5
Author: Manas R. Das
*/
#include <stdio.h>
// Main function to drive the program
int main(){
    // Declaring variables: i and j as loop counters, a[5] as an array to store 5 elements, indmin to store the index of the minimum element, and temp as a temporary variable for swapping
    int i, j, a[5], indmin, temp;

    // Prompting the user to enter 5 elements
    printf("\nEnter 5 Elements: \n");

    // Using a for loop to iterate over the array and reading user input to store in array a
    for (i = 0; i < 5; i++)
        scanf("%d", &a[i]);

    // Starting the selection sort algorithm to sort the array in ascending order
    for (i = 0; i < 4; i++){  // Looping through the array
        // Assuming the first unsorted element is the minimum
        indmin = i;

        // Iterating through the unsorted portion of the array to find the actual minimum element
        for (j = i + 1; j < 5; j++){
            // Checking if the current element is smaller than the previously assumed minimum
            if (a[j] < a[indmin])
                indmin = j; // Updating indmin to the index of the current minimum element
        }

        // Swapping the found minimum element with the first unsorted element
        temp = a[indmin];
        a[indmin] = a[i];
        a[i] = temp;
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
