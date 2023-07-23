#include <stdio.h>
#include <stdlib.h>

struct avl
{
    int ht;
    int data;
    struct avl*lchild;
    struct avl*rchild;
};

typedef struct avl*TREE;

int height(TREE root)
{
    if(root == NULL)
        return 0;
    else
        return root->ht;
}

int max(int a,int b)
{
    return (a>b)?a:b;
}

TREE create(int n)
{
    TREE newnode = (TREE) malloc(sizeof(struct avl));

    if(newnode == NULL)
        exit(0);
    else
    {
        newnode->data = n;
        newnode->rchild = NULL;
        newnode->lchild = NULL;
        newnode->ht = 1;
    }
    return newnode;
}

int balanced(TREE root)
{
    if(root == NULL)
        return 0;
    else
        return (height(root->lchild)- height(root->rchild));
}

TREE ll(TREE root)
{
    TREE x = root->lchild;
    TREE y = x->rchild;

    x->rchild = root;
    root->lchild = y;

    root->ht = 1 + max(height(root->lchild), height(root->rchild));
    x->ht = 1 + max(height(x->lchild), height(x->rchild));

    return x;
}


TREE rr(TREE root)
{
    TREE x = root->rchild;
    TREE y = x->lchild;

    x->lchild = root;
    root->rchild = y;

    root->ht = 1 + max(height(root->lchild), height(root->rchild));
    x->ht = 1 + max(height(x->lchild), height(x->rchild));

    return x;
}


void inorder(TREE root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        printf("%d ",root->data);
        inorder(root->rchild);
    }
}

void inorder1(TREE root, int level)
{
    if (root != NULL)
    {
        inorder1(root->rchild, level + 1);

        for (int i = 0; i < level; i++)
            printf("   ");

        printf("%d \n", root->data);

        inorder1(root->lchild, level + 1);
    }
}

TREE insert(TREE root, int n)
{
    if (root == NULL)
        return create(n);

    if (n < root->data)
    {
        root->lchild = insert(root->lchild, n);
    }
    else if (n > root->data)
    {
        root->rchild = insert(root->rchild, n);
    }
    else
        return root;

    root->ht = 1 + max(height(root->rchild), height(root->lchild));

    int balance = balanced(root);

    if (balance > 1 && n < root->lchild->data)
    {
        root = ll(root);
    }
    else if (balance < -1 && n > root->rchild->data)
    {
        root = rr(root);
    }

    return root;
}


int main()
{
    TREE root =NULL;
    int data,i;
    int level;
    printf("Enter data\n");
    for(i=0;i<7;i++)
    {
        scanf("%d",&data);
        root =  insert(root,data);
    }
    printf("\n");
    inorder(root);
    inorder1(root, 0);

    return 0;
}
