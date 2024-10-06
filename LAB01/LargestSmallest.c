/*
LAB 1: Program 2.
Date: 20 July 2024
Purpose: Enter 5 Elements into the Array & Find the Position of the Largest Number & Smallest Number.
Author: Manas R. Das
*/

#include<stdio.h>
void main(){
    int a[5], i, j, temp, indmax, indmin; // Variable Declaration
    // Prompting User to Enter 5 Elements
    printf("\nEnter the Array Elements:\n");
    for ( i = 0; i < 5; i++){
        scanf("%d", &a[i]);// Reading each Element into the Array
    }
    // Initializing Indices for Max and Min Elements
    indmax=0;
    indmin=0;
     // Finding the Indices of the Largest and Smallest Elements
    for ( i = 0; i < 5; i++){
        if(a[i]>a[indmax]){
            indmax= i; // Update Index of the Largest Element
        }
        if(a[i]<a[indmin]){
            indmin= i; // Update Index of the Smallest Element
        }
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
    // Printing the Smallest Element and its Position
    printf("\nSmallest Array Element: %d is at the Position: %d",a[0], indmin+1);
    // Printing the Largest Element and its Position
    printf("\nLargest Array Element: %d is at the Position: %d",a[4], indmax+1);
}

/*

OUTPUT:
Enter the Array Elements:
2
5
9
7
3

Smallest Array Element: 2 is at the Position: 1
Largest Array Element: 9 is at the Position: 3

*/