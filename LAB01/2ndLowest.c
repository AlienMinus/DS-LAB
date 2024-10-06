/*
LAB 1: Program 4.
Date: 20 July 2024
Purpose: Insert 5 elements into the array & delete the 2nd lowest element from that.
Author: Manas R. Das
*/

#include <stdio.h>
void main(){
    int i, j, index, a[5], temp; // Variable Declaration
    printf("\nEnter 5 Elements:\n"); // Prompting user to Enter 5 Elements
    for (i = 0; i < 5; i++){
        scanf("%d", &a[i]); // Reading 5 elements into the Array
    }
    // Sorting the Array in Ascending order using Bubble Sort
    for (i = 0; i < 5; i++){
        for (j = 0; j < 4 - i; j++){
            if (a[j] > a[j + 1]){
                // Swapping a[j] and a[j + 1]
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    // Checking if Deletion is possible 
    if (i >= 5 + 1){
        printf("\nDeletion Not Possible.\n");
    }
    else{
        // Shifting Elements to the Left to Delete the 2nd Lowest Element (which is at Index 1 after Sorting)
        for (i = 1; i < 4; i++){
            a[i] = a[i + 1];
        }
    }
    // Printing the Array after Deleting the 2nd Lowest Element
    printf("\nThe Array after Deleting the 2nd Lowest Element is:\n");
    for (i = 0; i < 4; i++){
        printf("%d\n", a[i]);
    }
}

/*

OUTPUT:
Enter 5 Elements:
1
2
3
4
5

The Array after Deleting the 2nd Lowest Element is:
1
3
4
5

*/