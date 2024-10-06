/*
LAB 2: Program 2.
Date: 24 July 2024
Purpose: WAP to Add two matrices & display the resultant Matrix
Author: Manas R. Das
*/
#include <stdio.h>
int main()
{
    int A[10][10], B[10][10], sum[10][10], r, c, i, j; // Variable Declaration
    // Prompting User to Enter the Number of Rows
    printf("Enter the Number of Rows (Between 1 & 10):");
    scanf("%d", &r);
    // Prompting User to Enter the Number of Columns
    printf("Enter the Number of Columns (Between 1 & 10):");
    scanf("%d", &c);
    // Prompting User to Enter the Elements of the First Matrix
    printf("Enter the Elements of Matrix A:\n");
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){
            printf("Enter Element A[%d][%d]: ",i+1,j+1);
            scanf("%d", &A[i][j]); // Reading each Element into the First Matrix
        }
    }
    // Prompting User to Enter the Elements of the Second Matrix
    printf("Enter the Elements of matrix B:\n");
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){
            printf("Enter Element B[%d][%d]: ",i+1,j+1);
            scanf("%d", &B[i][j]); // Reading each Element into the Second Matrix
        }
    }
    // Adding Corresponding Elements of the Two Matrices
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){
            sum[i][j] = A[i][j] + B[i][j]; // Storing the Sum in the Resultant Matrix
        }
    }
    // Printing the Resultant Matrix
    printf("The Sum of the Two Matrices is:\n");
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){
            printf("%d\t", sum[i][j]); // Printing each Element of the Resultant Matrix
            if (j == c - 1){
                printf("\n\n"); // Printing a New Line at the End of each Row
            }
        }
    }
    return 0; // Indicating that the Program Ended Successfully
}

/*

OUTPUT:
Enter the Number of Rows (Between 1 & 10):2
Enter the Number of Columns (Between 1 & 10):2
Enter the Elements of Matrix A:
Enter Element A[1][1]: 2
Enter Element A[1][2]: 2
Enter Element A[2][1]: 2
Enter Element A[2][2]: 2
Enter the Elements of matrix B:
Enter Element B[1][1]: 2
Enter Element B[1][2]: 2
Enter Element B[2][1]: 2
Enter Element B[2][2]: 2
The Sum of the Two Matrices is:
4       4

4       4

*/
