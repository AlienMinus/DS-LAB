/*
LAB 1: Program 3.
Date: 20 July 2024
Purpose: Enter 5 Elements into the Array & Find the 2nd Highest Element from that Array.
Author: Manas R. Das
*/

#include <stdio.h>
void main(){
    int i, j, a[5], temp; // Variable Declaration
    printf("\nEnter 5 Elements:\n"); // Prompting User to Enter 5 Elements
    for (i = 0; i < 5; i++){
        scanf("%d", &a[i]); // Reading 5 Elements into the Array
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
    // Printing the Second Highest Element (which is the Second Last Element after Sorting)
    printf("\nThe Second Highest Element: %d\n", a[3]);
}

/*

OUTPUT:
Enter 5 Elements:
1
7
4
9
3

The Second Highest Element: 7

*/