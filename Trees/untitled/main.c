#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree* rchild;
    struct tree* lchild;
};

typedef struct tree* TREE;

TREE create(int n) {
    TREE newnode = (TREE)malloc(sizeof(struct tree));
    if (newnode == NULL)
        exit(0);
    else {
        newnode->data = n;
        newnode->rchild = newnode->lchild = NULL;
    }
    return newnode;
}

void insert(TREE* root, int key) {
    if (*root == NULL) {
        *root = create(key);
    } else {
        int leftChildData, rightChildData;
        printf("Enter the value of the left child of %d (0 for NULL): ", key);
        scanf("%d", &leftChildData);
        insert(&(*root)->lchild, leftChildData);

        printf("Enter the value of the right child of %d (0 for NULL): ", key);
        scanf("%d", &rightChildData);
        insert(&(*root)->rchild, rightChildData);
    }
}

int checkSumProperty(TREE root) {
    if (root == NULL || (root->lchild == NULL && root->rchild == NULL))
        return 1;

    int leftsum = 0;
    int rightsum = 0;

    if (root->lchild != NULL)
        leftsum = (root->lchild)->data;

    if (root->rchild != NULL)
        rightsum = (root->rchild)->data;

    if (root->data == leftsum + rightsum)
        return checkSumProperty(root->lchild) && checkSumProperty(root->rchild);

    return 0;
}

int main() {
    TREE root = NULL;
    int rootData;
    printf("Enter the value of the root node: ");
    scanf("%d", &rootData);

    insert(&root, rootData);

    if (checkSumProperty(root)) {
        printf("The binary tree satisfies the children sum property.\n");
    } else {
        printf("The binary tree does not satisfy the children sum property.\n");
    }

    return 0;
}
