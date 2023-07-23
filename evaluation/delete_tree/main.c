#include <stdio.h>
#include <stdlib.h>


struct trees
{
    int data;
    struct trees*right;
    struct trees*left;
};

typedef struct trees*ROOT;

ROOT create_node(int n)//ROOT NODE CREATION
{
    ROOT newnode;
    newnode = (ROOT) malloc(sizeof(struct trees));

    if(newnode == NULL)
    {
        printf("Node not created.");
        exit(0);
    }

    newnode->data = n;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

ROOT insert_left(ROOT root,int n)
{
    root->left = create_node(n);
    return root->left;
}

ROOT insert_right(ROOT root,int n)
{
    root->right = create_node(n);
    return root->right;
}

struct TreeNode* findMin(struct TreeNode* root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}


int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}
struct TreeNode* deleteNode(struct TreeNode* root, int value) {
    if (root == NULL)
        return root;

    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = findMin(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }

    return root;
}




int main() {
    struct TreeNode* root = NULL;
    srand(time(NULL));  // Seed the random number generator with the current time

    // Generate and insert random values into the tree
    int i;
    for (i = 0; i < 10; i++) {
        int value = generateRandomNumber(1, 100);  // Generate a random number between 1 and 100
        printf("Inserting %d into the tree...\n", value);
        root = insert(root, value);
    }

    // Delete a randomly chosen value from the tree
    int valueToDelete = generateRandomNumber(1, 100);
    printf("Deleting %d from the tree...\n", valueToDelete);
    root = deleteNode(root, valueToDelete);

    // Print the remaining values in the tree
    printf("Remaining values in the tree:\n");
    inorderTraversal(root);

    return 0;
}
