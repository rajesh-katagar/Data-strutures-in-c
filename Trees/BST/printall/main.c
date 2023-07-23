#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree* rchild;
    struct tree* lchild;
};

typedef struct tree* TREE;

TREE create(TREE root, int n)
{
    TREE newnode = (TREE)malloc(sizeof(struct tree));

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    else
    {
        newnode->data = n;
        newnode->rchild = newnode->lchild = NULL;
    }
    return newnode;
}

TREE insert(TREE root, int n)
{
    if (root == NULL)
        root = create(root, n);
    else if (root->data > n)
        root->lchild = insert(root->lchild, n);
    else
        root->rchild = insert(root->rchild, n);

    return root;
}

void printPathsUtil(TREE node, int path[], int length)
{
    if (node == NULL)
        return;

    path[length] = node->data;
    length++;

    if (node->lchild == NULL && node->rchild == NULL)
    {
        for (int i = 0; i < length; i++)
            printf("%d ", path[i]);
        printf("\n");
    }
    else
    {
        printPathsUtil(node->lchild, path, length);
        printPathsUtil(node->rchild, path, length);
    }
}

void printPaths(TREE root)
{
    if (root == NULL)
        return;

    int* path = (int*)malloc(100 * sizeof(int));
    if (path == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Root-to-leaf paths:\n");
    printPathsUtil(root, path, 0);

    free(path);
}

int main()
{
    TREE root = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of nodes.\n");
        return 0;
    }

    printf("Enter the values of nodes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printPaths(root);

    return 0;
}
