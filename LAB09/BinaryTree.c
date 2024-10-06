/*
LAB 9: Program 1.
Date: 24 August 2024
Purpose: WAP in C using function to perform the following operation on a binary tree 1.creation 2.insertion
Author: Manas R. Das
*/

#include <stdio.h>
#include <stdlib.h>

// Defining the node structure with typedef
typedef struct node {
  int item;               // Storing the value of the node
  struct node* left;      // Pointer to the left child
  struct node* right;     // Pointer to the right child
} Node;

// Performing inorder traversal (Left -> Root -> Right)
void inorderTraversal(Node* root) {
  if (root == NULL) return; // Returning if the current node is NULL
  inorderTraversal(root->left); // Recursively traversing the left subtree
  printf("%d ->", root->item);  // Printing the current node's value
  inorderTraversal(root->right); // Recursively traversing the right subtree
}

// Performing preorder traversal (Root -> Left -> Right)
void preorderTraversal(Node* root) {
  if (root == NULL) return; // Returning if the current node is NULL
  printf("%d ->", root->item);  // Printing the current node's value
  preorderTraversal(root->left); // Recursively traversing the left subtree
  preorderTraversal(root->right); // Recursively traversing the right subtree
}

// Performing postorder traversal (Left -> Right -> Root)
void postorderTraversal(Node* root) {
  if (root == NULL) return; // Returning if the current node is NULL
  postorderTraversal(root->left); // Recursively traversing the left subtree
  postorderTraversal(root->right); // Recursively traversing the right subtree
  printf("%d ->", root->item);  // Printing the current node's value
}

// Creating a new node with a given value
Node* createNode(int value) {
  Node* newNode = malloc(sizeof(Node)); // Allocating memory for a new node
  if (newNode == NULL) {
    fprintf(stderr, "Memory allocation failed!\n");
    exit(EXIT_FAILURE); // Exit if memory allocation fails
  }
  newNode->item = value;    // Setting the value of the new node
  newNode->left = NULL;     // Initializing left child as NULL
  newNode->right = NULL;    // Initializing right child as NULL

  return newNode; // Returning the newly created node
}

// Inserting a new node on the left of the current node
Node* insertLeft(Node* root, int value) {
  if (root == NULL) return NULL; // Check if root is NULL
  root->left = createNode(value); // Creating and assigning a new node to the left child
  return root->left; // Returning the newly created node
}

// Inserting a new node on the right of the current node
Node* insertRight(Node* root, int value) {
  if (root == NULL) return NULL; // Check if root is NULL
  root->right = createNode(value); // Creating and assigning a new node to the right child
  return root->right; // Returning the newly created node
}

int main() {
  // Creating the root node with value 1
  Node* root = createNode(1);
  // Inserting nodes
  insertLeft(root, 2); // Inserting 2 on the left of root
  insertRight(root, 3); // Inserting 3 on the right of root
  insertLeft(root->left, 4); // Inserting 4 on the left of node 2
  insertRight(root->left, 5); // Inserting 5 on the right of node 4
  insertLeft(root->right, 6); // Inserting 6 on the left of node 3
  insertRight(root->right, 7); // Inserting 7 on the right of node 3

  // Performing and printing the inorder traversal
  printf("Inorder traversal \n");
  inorderTraversal(root);
  printf("\n");

  // Performing and printing the preorder traversal
  printf("Preorder traversal \n");
  preorderTraversal(root);
  printf("\n");

  // Performing and printing the postorder traversal
  printf("Postorder traversal \n");
  postorderTraversal(root);
  printf("\n");

  return 0; // Returning success
}

/*
OUTPUT:
Inorder traversal 
4 ->2 ->5 ->1 ->6 ->3 ->7 ->
Preorder traversal 
1 ->2 ->4 ->5 ->3 ->6 ->7 ->
Postorder traversal 
4 ->5 ->2 ->6 ->7 ->3 ->1 ->

*/