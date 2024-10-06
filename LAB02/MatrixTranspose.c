/*
LAB 2: Program 3.
Date: 24 July 2024
Purpose: WAP to find the Transpose of a Matrix.
Author: Manas R. Das
*/
#include <stdio.h>
int main()
{
    int a[10][10], b[10][10], sum[10][10], r, c, i, j; // Variable Declaration
    // Prompting User to Enter the Number of Rows
    printf("\nEnter the number of rows (Between 1 & 10):");
    scanf("%d", &r);
    // Prompting User to Enter the Number of Columns
    printf("\nEnter the number of columns (Between 1 & 10):");
    scanf("%d", &c);
    // Prompting User to Enter the Elements of the Matrix
    printf("\nEnter the elements of Matrix:\n");
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){
            printf("Enter Element a[%d][%d]:", i + 1, j + 1);
            scanf("%d", &a[i][j]); // Reading each Element into the Matrix
        }
    }
    // Printing the Matrix Entered by the User
    printf("\nThe Matrix Entered:\n");
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){
            printf("%d\t", a[i][j]); // Printing each Element of the Matrix
            if (j == c - 1)
                printf("\n\n"); // Printing a New Line at the End of each Row
        }
    }
    // Computing the Transpose of the Matrix
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){
            b[j][i] = a[i][j]; // Assigning the Transposed Element
        }
    }
    // Printing the Transposed Matrix
    printf("\nThe Transposed Matrix:\n");
    // Row-Columns Swapping.
    for (i = 0; i < c; i++){
        for (j = 0; j < r; j++){
            printf("%d\t", b[i][j]); // Printing each Element of the Transposed Matrix
            if (j == r - 1)
                printf("\n\n"); // Printing a New Line at the End of each Row
        }
    }
    return 0; // Indicating that the Program Ended Successfully
}

/*

OUTPUT:
Enter the number of rows (Between 1 & 10):2

Enter the number of columns (Between 1 & 10):3

Enter the elements of Matrix:
Enter Element a[1][1]:1
Enter Element a[1][2]:2
Enter Element a[1][3]:3
Enter Element a[2][1]:4
Enter Element a[2][2]:5
Enter Element a[2][3]:6

The Matrix Entered:
1       2       3

4       5       6


The Transposed Matrix:
1       4

2       5

3       6

*/