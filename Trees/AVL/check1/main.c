#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
    int height;
};
struct node *getnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->right = NULL;
    newnode->left = NULL;
    newnode->height = 1;
    return newnode;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int getheight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return n->height;
    }
}
int balancefactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return getheight(n->left) - getheight(n->right);
    }
}
struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getheight(y->right), getheight(y->left));
    x->height = max(getheight(x->right), getheight(x->left));

    return x;
}
struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getheight(y->right), getheight(y->left));
    x->height = max(getheight(x->right), getheight(x->left));

    return y;
}


struct node *insert(struct node *newnode, int data)
{
    if (newnode == NULL)
    {
        return getnode(data);
    }
    if (data < newnode->data)
    {
        newnode->left = insert(newnode->left, data);
    }
    else if (data > newnode->data)
    {
        newnode->right = insert(newnode->right, data);
    }
    return newnode;
    newnode->height = 1 + max(getheight(newnode->left), getheight(newnode->right));
    int bf = balancefactor(newnode);

    // left left
    if (bf > 1 && data < newnode->left->data)
    {
        return rightrotate(newnode);
    }
    // right right
    if (bf < -1 && data > newnode->right->data)
    {
        return leftrotate(newnode);
    }
    // left right
    if (bf > 1 && data > newnode->left->data)
    {
        newnode->left = leftrotate(newnode->left);
        rightrotate(newnode);
    }
    //right left
    if (bf < -1 && data < newnode->right->data)
    {
        newnode->right = rightrotate(newnode->right);
        leftrotate(newnode);
    }
}