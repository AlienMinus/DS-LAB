/*
LAB -1: Program 1.
Date: 28 September 2024
Purpose: WAP in C to 
a. Create an AVL Tree of N Integers: 8, 10, 3, 1, 6, 14, 7 
b. Traverse the AVL Tree in Inorder 
c. Traverse the AVL Tree in Preorder 
d. Traverse the AVL Tree Postorder
Author: Manas R. Das
*/
#include <stdio.h>
#include <stdlib.h>

// Defining a structure for the AVL node
struct Node {
    int data;
    struct Node *left, *right;
    int height;
};

// Function to get the height of a node
int getHeight(struct Node* node) {
    return (node == NULL) ? 0 : node->height;
}

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    newNode->height = 1; // New node is initially at height 1
    return newNode;
}

// Function to get the balance factor
int getBalance(struct Node* node) {
    return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Right Rotation (LL Rotation)
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    
    return x;
}

// Left Rotation (RR Rotation)
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    
    return y;
}

// Insert a node into the AVL tree
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
    else
        return root; // No duplicates allowed

    root->height = 1 + (getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) : getHeight(root->right));

    int balance = getBalance(root);
    
    // Left Heavy (LL Case)
    if (balance > 1 && value < root->left->data)
        return rightRotate(root);
    
    // Right Heavy (RR Case)
    if (balance < -1 && value > root->right->data)
        return leftRotate(root);
    
    // Left-Right Heavy (LR Case)
    if (balance > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    // Right-Left Heavy (RL Case)
    if (balance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

// Function for inorder traversal (left-root-right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function for preorder traversal (root-left-right)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function for postorder traversal (left-right-root)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int elements[] = {8, 10, 3, 1, 6, 14, 7};
    int n = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < n; i++) {
        root = insertNode(root, elements[i]);
    }

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

/*
OUTPUT:
Inorder Traversal: 1 3 6 7 8 10 14 
Preorder Traversal: 8 3 1 6 7 10 14 
Postorder Traversal: 1 7 6 3 14 10 8 
*/