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

int sum_count(TREE root) {
    if (root == NULL || (root->lchild == NULL && root->rchild == NULL))
        return 0;

    int leftsum = 0;
    int rightsum = 0;

    if (root->lchild != NULL)
        leftsum = (root->lchild)->data;

    if (root->rchild != NULL)
        rightsum = (root->rchild)->data;

    int count = 0;
    if (root->data == leftsum + rightsum)
        count++;

    int leftcount = sum_count(root->lchild);
    int rightcount = sum_count(root->rchild);

    return count + rightcount + leftcount;
}

int main() {
    TREE root = NULL;

    while (1)
    {
        int rootData;
        printf("Enter the value of the root node  ");
        scanf("%d", &rootData);
        if (rootData == 0)
            break;

        if (root == NULL)
        {
            root = create(rootData);
        } else
        {
            printf("Enter the value of the left child of the root node ");
            int leftChildData;
            scanf("%d", &leftChildData);
            {
                root->lchild = create(leftChildData);
            }

            printf("Enter the value of the right child of the root node  ");
            int rightChildData;
            scanf("%d", &rightChildData);
            {
                root->rchild = create(rightChildData);
            }

            int count = sum_count(root);

            printf("Binary tree has equal %d node\n", count);

            root = NULL;
        }
    }

    return 0;
}
