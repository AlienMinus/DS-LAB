/*
LAB 15: Program 1.
Date: 28 September 2024
Purpose: WAP in C to for the following operations on Graph(G) a. Create a Graph N using Adjacency Matrix
Author: Manas R. Das
*/
#include <stdio.h>

// Declaring the number of vertices and edges
int N, M;

// Defining the function to create the adjacency matrix
void createAdjMatrix(int Adj[][N + 1], int arr[][2]) {
    
    // Initializing all values in the adjacency matrix to zero
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            Adj[i][j] = 0;
        }
    }

    // Traversing through the array of edges
    for (int i = 0; i < M; i++) {
        
        // Finding the vertices connected by the edge
        int x = arr[i][0];
        int y = arr[i][1];

        // Updating the adjacency matrix to indicate the edge between vertices
        Adj[x][y] = 1;
        Adj[y][x] = 1;
    }
}

// Defining the function to print the adjacency matrix
void printAdjMatrix(int Adj[][N + 1]) {

    // Traversing the adjacency matrix to print its values
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {

            // Printing the value at the current position
            printf("%d ", Adj[i][j]);
        }
        // Moving to the next line after each row
        printf("\n");
    }
}

// Starting the main function
int main() {

    // Setting the number of vertices
    N = 5;

    // Defining the edges between the vertices
    int arr[][2] = {{1, 2}, {2, 3}, {4, 5}, {1, 5}};

    // Calculating the number of edges
    M = sizeof(arr) / sizeof(arr[0]);

    // Declaring the adjacency matrix with appropriate size
    int Adj[N + 1][N + 1];

    // Calling the function to create the adjacency matrix
    createAdjMatrix(Adj, arr);

    // Printing the adjacency matrix
    printf("Adjacency Matrix:\n");
    printAdjMatrix(Adj);

    // Returning 0 to indicate successful execution
    return 0;
}

/*
OUTPUT:
Adjacency Matrix:
0 1 0 0 1 
1 0 1 0 0 
0 1 0 0 0 
0 0 0 0 1 
1 0 0 1 0 
*/