/*
LAB 10: Program 1.
Date: 28 August 2024
Purpose: WAP in C using function to perform the following operation on a binary tree 1.creation 2.insertion 3.deletion
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

// Finding the inorder successor (smallest in the right subtree)
Node* findInorderSuccessor(Node* node) {
  Node* current = node;
  while (current && current->left != NULL) {
    current = current->left; // Moving to the leftmost node
  }
  return current;
}

// Deleting a node from the binary tree
Node* deleteNode(Node* root, int key) {
  // Base case: If the tree is empty
  if (root == NULL) return root;

  // If the key to be deleted is smaller than the root's key,
  // then it lies in the left subtree
  if (key < root->item) {
    root->left = deleteNode(root->left, key);
  }
  // If the key to be deleted is greater than the root's key,
  // then it lies in the right subtree
  else if (key > root->item) {
    root->right = deleteNode(root->right, key);
  }
  // If the key is the same as the root's key, then this is the node to be deleted
  else {
    // Node with only one child or no child
    if (root->left == NULL) {
      Node* temp = root->right;
      free(root); // Free the memory of the node to be deleted
      return temp;
    } else if (root->right == NULL) {
      Node* temp = root->left;
      free(root); // Free the memory of the node to be deleted
      return temp;
    }

    // Node with two children: Get the inorder successor
    Node* temp = findInorderSuccessor(root->right);

    // Copy the inorder successor's content to this node
    root->item = temp->item;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->item);
  }

  return root;
}

int main() {
  // Creating the root node with value 1
  Node* root = createNode(1);
  // Inserting nodes
  insertLeft(root, 2); // Inserting 2 on the left of root
  insertRight(root, 3); // Inserting 3 on the right of root
  insertLeft(root->left, 4); // Inserting 4 on the left of node 2
  insertRight(root->left, 5); // Inserting 5 on the right of node 2
  insertLeft(root->right, 6); // Inserting 6 on the left of node 3
  insertRight(root->right, 7); // Inserting 7 on the right of node 3

  printf("\nBefore Deletion:\n");
  // Performing and printing the inorder traversal before deletion
  printf("Inorder traversal:\n");
  inorderTraversal(root);
  printf("\n");

  // Performing and printing the preorder traversal before deletion
  printf("Preorder traversal:\n");
  preorderTraversal(root);
  printf("\n");

  // Performing and printing the postorder traversal before deletion
  printf("Postorder traversal:\n");
  postorderTraversal(root);
  printf("\n");

  // Deleting a node with value 3
  root = deleteNode(root, 3);
  printf("\nDeleted Node is 3.\n");

  printf("\nAfter Deletion:\n");
  // Performing and printing the inorder traversal after deletion
  printf("Inorder traversal:\n");
  inorderTraversal(root);
  printf("\n");

  // Performing and printing the preorder traversal after deletion
  printf("Preorder traversal:\n");
  preorderTraversal(root);
  printf("\n");

  // Performing and printing the postorder traversal after deletion
  printf("Postorder traversal:\n");
  postorderTraversal(root);
  printf("\n");

  return 0; // Returning success
}

/*
OUTPUT:
Before Deletion:
Inorder traversal:
4 ->2 ->5 ->1 ->6 ->3 ->7 ->
Preorder traversal:
1 ->2 ->4 ->5 ->3 ->6 ->7 ->
Postorder traversal:
4 ->5 ->2 ->6 ->7 ->3 ->1 ->

Deleted Node is 3.

After Deletion:
Inorder traversal:
4 ->2 ->5 ->1 ->6 ->7 ->
Preorder traversal:
1 ->2 ->4 ->5 ->7 ->6 ->
Postorder traversal:
4 ->5 ->2 ->6 ->7 ->1 ->
*/
