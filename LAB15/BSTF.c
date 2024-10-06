/*
LAB 15: Program 1.
Date: 28 September 2024
Purpose: WAP in C to 
a. Create a BST of N Integers: 8, 10, 3, 1, 6, 14, 7 
b. Traverse the BST in Inorder 
c. Traverse the BST in Preorder 
d. Traverse the BST postorder
Author: Manas R. Das
*/
#include <stdio.h>
#include <stdlib.h>

// Defining a structure for the BST node
struct Node {
    int data;               // Storing the node's value
    struct Node *left, *right;  // Pointers to the left and right child nodes
};

// Function to create a new node in the BST
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocating memory for the new node
    newNode->data = value;   // Storing the value in the new node
    newNode->left = newNode->right = NULL;  // Initializing left and right child pointers to NULL
    return newNode;          // Returning the newly created node
}

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        // Creating the root node if the tree is empty
        return createNode(value);
    }

    if (value < root->data) {
        // Inserting the value into the left subtree if it's smaller than the current node
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        // Inserting the value into the right subtree if it's larger than the current node
        root->right = insertNode(root->right, value);
    }

    return root;  // Returning the root node after insertion
}

// Function for inorder traversal (left-root-right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);      // Recursively traversing the left subtree
        printf("%d ", root->data);         // Printing the current node's value
        inorderTraversal(root->right);     // Recursively traversing the right subtree
    }
}

// Function for preorder traversal (root-left-right)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);         // Printing the current node's value
        preorderTraversal(root->left);     // Recursively traversing the left subtree
        preorderTraversal(root->right);    // Recursively traversing the right subtree
    }
}

// Function for postorder traversal (left-right-root)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);    // Recursively traversing the left subtree
        postorderTraversal(root->right);   // Recursively traversing the right subtree
        printf("%d ", root->data);         // Printing the current node's value
    }
}

// Main function to demonstrate the operations
int main() {
    struct Node* root = NULL;  // Initializing the root of the tree to NULL
    int elements[] = {8, 10, 3, 1, 6, 14, 7};
    int n = sizeof(elements) / sizeof(elements[0]);

    // Inserting values into the BST
    for (int i = 0; i < n; i++) {
        root = insertNode(root, elements[i]);    // Inserting the element into the BST
    }

    // Performing and displaying traversals
    printf("Inorder Traversal: ");
    inorderTraversal(root);                // Performing an inorder traversal
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);               // Performing a preorder traversal
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);              // Performing a postorder traversal
    printf("\n");

    return 0;                              // Exiting the program successfully
}

/*
OUTPUT:
Inorder Traversal: 1 3 6 7 8 10 14 
Preorder Traversal: 8 3 1 6 7 10 14 
Postorder Traversal: 1 7 6 3 14 10 8
*/