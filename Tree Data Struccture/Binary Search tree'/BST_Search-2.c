#include <stdio.h>
#include <stdlib.h>

// ----------------------
// Structure of a Node
// ----------------------
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// ----------------------
// Create a new node
// ----------------------
struct node* createNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// ----------------------
// Insert in BST
// ----------------------
struct node* insert(struct node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } 
    else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

// ----------------------
// Inorder Traversal (Sorted Output)
// ----------------------
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// ----------------------
// Search in BST
// ----------------------
struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// ----------------------
// Check if Tree is BST
// ----------------------
int isBST(struct node* root) {
    static struct node* prev = NULL;

    if (root != NULL) {
        if (!isBST(root->left))
            return 0;

        if (prev != NULL && root->data <= prev->data)
            return 0;

        prev = root;

        return isBST(root->right);
    }

    return 1;
}

// ----------------------
// Main Function
// ----------------------
int main() {

    struct node* root = NULL;

    // Inserting elements
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 4);

    printf("Inorder Traversal (sorted): ");
    inorder(root);

    // Search
    int key = 10;
    struct node* result = search(root, key);

    if (result != NULL)
        printf("\nFound: %d", result->data);
    else
        printf("\nElement %d not found", key);

    // Check BST
    if (isBST(root))
        printf("\nTree is a VALID BST");
    else
        printf("\nTree is NOT a BST");

    return 0;
}
