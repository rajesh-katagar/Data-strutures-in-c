#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int item;
    struct node* left;
    struct node* right;
};

typedef struct node* ROOT;

// Inorder traversal
void inorderTraversal(ROOT root, FILE* file) {
    if (root == NULL)
        return;
    inorderTraversal(root->left, file);
    fprintf(file, "%d  ", root->item);
    inorderTraversal(root->right, file);
}

// Preorder traversal
void preorderTraversal(ROOT root, FILE* file) {
    if (root == NULL)
        return;
    fprintf(file, "%d  ", root->item);
    preorderTraversal(root->left, file);
    preorderTraversal(root->right, file);
}

// Postorder traversal
void postorderTraversal(ROOT root, FILE* file) {
    if (root == NULL)
        return;
    postorderTraversal(root->left, file);
    postorderTraversal(root->right, file);
    fprintf(file, "%d ", root->item);
}

// Create a new Node
ROOT createNode(int value) {
    ROOT newNode = malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert on the left of the node
ROOT insertLeft(ROOT root, int value) {
    root->left = createNode(value);
    return root->left;
}

// Insert on the right of the node
ROOT insertRight(ROOT root, int value) {
    root->right = createNode(value);
    return root->right;
}

// Generate random binary tree and store elements in a file
void generateRandomTree(int numNodes) {
    FILE* fp = fopen("input.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.");
        return;
    }

    srand(time(0)); // Set the seed for random number generation

    for (int i = 0; i < numNodes; i++)
    {
        int value = rand() % 100; // Generate random values between 0 and 99
        fprintf(fp, "%d\n", value);
    }

    fclose(fp);
}

ROOT constructTreeFromFile()
{
    FILE* fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.");
        return NULL;
    }

    ROOT root = NULL;
    int value;
    while (fscanf(fp, "%d", &value) != EOF)
    {
        if (root == NULL)
        {
            root = createNode(value);
        }
        else {
            ROOT current = root;
            while (1) {
                if (value <= current->item) {
                    if (current->left == NULL) {
                        current->left = createNode(value);
                        break;
                    }
                    else {
                        current = current->left;
                    }
                }
                else {
                    if (current->right == NULL) {
                        current->right = createNode(value);
                        break;
                    }
                    else {
                        current = current->right;
                    }
                }
            }
        }
    }

    fclose(fp);
    return root;
}

int main() {
    int numNodes = 5;

    generateRandomTree(numNodes);
    ROOT root = constructTreeFromFile();

    FILE* inorderFile = fopen("inorder.txt", "w");
    FILE* preorderFile = fopen("preorder.txt", "w");
    FILE* postorderFile = fopen("postorder.txt", "w");

    if (inorderFile == NULL || preorderFile == NULL || postorderFile == NULL) {
        printf("Error opening files.");
        return 1;
    }

    inorderTraversal(root, inorderFile);
    printf("\n");

    preorderTraversal(root, preorderFile);
    printf("\n");

    postorderTraversal(root, postorderFile);
    printf("\n");

    fclose(inorderFile);
    fclose(preorderFile);
    fclose(postorderFile);

    return 0;
}
