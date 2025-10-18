#include <stdio.h>
#include <stdlib.h>

// Define a structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Create root node
    struct Node* root = createNode(1);

    // Create child nodes
    root->left = createNode(2);
    root->right = createNode(3);

    // Example of linking more nodes
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Print data to show structure
    printf("Root: %d\n", root->data);
    printf("Left Child of Root: %d\n", root->left->data);
    printf("Right Child of Root: %d\n", root->right->data);
    printf("Left Child of Left Child: %d\n", root->left->left->data);
    printf("Right Child of Left Child: %d\n", root->left->right->data);

    return 0;
}
