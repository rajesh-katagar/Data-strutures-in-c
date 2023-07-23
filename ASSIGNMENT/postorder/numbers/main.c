#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a number into the binary tree
Node* insertNumber(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNumber(root->left, data);
    } else if (data > root->data) {
        root->right = insertNumber(root->right, data);
    }

    return root;
}

// Function to perform level-order traversal and print the binary tree
void printBinaryTree(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    printBinaryTree(root->right, level + 1);

    for (int i = 0; i < level; i++) {
        printf("    ");
    }

    printf("%d\n", root->data);

    printBinaryTree(root->left, level + 1);
}

int main() {
    FILE* file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    Node* root = NULL;
    int num;

    while (fscanf(file, "%d", &num) == 1) {
        root = insertNumber(root, num);
    }

    fclose(file);

    printf("Binary Tree Representation:\n");
    printBinaryTree(root, 0);



    return 0;
}
