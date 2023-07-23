#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree* rchild;
    struct tree* lchild;
};

typedef struct tree* TREE;

TREE create(int n)
{
    TREE newnode = (TREE)malloc(sizeof(struct tree));

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }

    newnode->data = n;
    newnode->rchild = newnode->lchild = NULL;

    return newnode;
}

TREE insert(TREE root, int n)
{
    if (root == NULL)
        root = create(n);
    else if (root->data > n)
        root->lchild = insert(root->lchild, n);
    else
        root->rchild = insert(root->rchild, n);

    return root;
}

int identical(TREE root1, TREE root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;
    if (root1->data != root2->data)
        return 0;
    else
        return identical(root1->lchild, root2->lchild) && identical(root1->rchild, root2->rchild);
}


void inorder(TREE root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        printf("%d",root->data);
        inorder(root->rchild);
    }

}

int main()
{
    TREE root1 = NULL;
    TREE root2 = NULL;
    int n, data;

    printf("Enter the number of nodes for Tree 1: ");
    scanf("%d", &n);

    printf("Enter the values of nodes for Tree 1: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root1 = insert(root1, data);
    }
    printf("\n");

    printf("Enter the number of nodes for Tree 2: ");
    scanf("%d", &n);

    printf("Enter the values of nodes for Tree 2: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root2 = insert(root2, data);
    }

    inorder(root1);
    printf("\n");
    inorder(root2);
    printf("\n");

    if (identical(root1, root2))
    {
        printf("Trees are identical.\n");
    }
    else
    {
        printf("Trees are not identical.\n");
    }

    return 0;
}
