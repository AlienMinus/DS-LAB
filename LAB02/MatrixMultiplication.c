/*
LAB 2: Program 1.
Date: 24 July 2024
Purpose: WAP to multiply two matrices & display the resultant Matrix
Author: Manas R. Das
*/
#include <stdio.h>
int main()
{
    int a[10][10], b[10][10], c[10][10], n, i, j, k; // Variable Declaration
    // Prompting User to Enter the Order of the Matrices
    printf("Enter the value of order of The Matrix N(N<=10):");
    scanf("%d", &n);
    // Prompting User to Enter the Elements of the First Matrix
    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            scanf("%d", &a[i][j]); // Reading each Element into the First Matrix
        }
    }
    // Prompting User to Enter the Elements of the Second Matrix
    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            scanf("%d", &b[i][j]); // Reading each Element into the Second Matrix
        }
    }
    // Multiplying the Matrices 
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            c[i][j] = 0; // Initializing the Resultant Matrix Element
            for (k = 0; k < n; k++){
                c[i][j] += a[i][k] * b[k][j]; // Performing Multiplication and Adding to the Result
            }
        }
    }
    // Printing the Resultant Matrix
    printf("The product of the two matrices is:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%d\t", c[i][j]); // Printing each Element of the Resultant Matrix
        }
        printf("\n\n"); // Printing a New Line at the End of each Row
    }
    return 0; // Indicating that the Program Ended Successfully
}

/*

OUTPUT:
Enter the value of order of The Matrix N(N<=10):2
Enter the elements of matrix A:
2
2
2
2
Enter the elements of matrix B:
2
2
2
2
The product of the two matrices is:
8       8

8       8

*/