/*
LAB 1: Program 1.
Date: 20 July 2024
Purpose: Enter n Elements into the Array & Display Them.
Author: Manas R. Das
*/
#include <stdio.h>
void main()
{
    int i, size, a[50]; // Variable Declaration
    // Prompting User to Define the Size of the Array
    printf("\nDefine the Array Size:");
    scanf("%d", &size);

    // Prompting User to Enter Array Elements
    printf("\nEnter Array Elements:\n");
    for (i = 0; i < size; i++)
        scanf("%d", &a[i]); // Reading each Element into the Array
    
    // Displaying the Array Elements
    printf("\nArray Elements are:\n");
    for (i = 0; i < size; i++)
        printf("%d\n", a[i]); // Printing each Element of the Array
}

/*
OUTPUT:

Define the Array Size:5

Enter Array Elements:
1
2
3
4
5

Array Elements are:
1
2
3
4
5

*/