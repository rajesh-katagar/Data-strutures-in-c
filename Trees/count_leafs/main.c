#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tree
{
    int data;
    struct tree*rchild;
    struct tree*lchild;
};

typedef struct tree*TREE;

TREE create(int n)
{
    TREE newnode = (TREE) malloc(sizeof(struct tree));

    if(newnode == NULL)
        exit(0);
    newnode->data = n;
    newnode->rchild = newnode->lchild = NULL;

    return newnode;
}

TREE insert(TREE root,int n)
{
    if(root == NULL)
        root = create(n);
    else if(root->data > n)
        root->lchild = insert(root->lchild,n);
    else
        root->rchild = insert(root->rchild,n);

    return root;
}

int count(TREE root)
{
    if(root == NULL)
        return 0;
    if(root->lchild == NULL && root->rchild == NULL)
        return 1;
    else
        return count(root->lchild) + count(root->rchild);
}


void inorder(TREE root)
{
    if(root!= NULL)
    {
        inorder(root->lchild);
        printf("%d ",root->data);
        inorder(root->rchild);
    }
}

int main()
{
    int n,c,random = 0;
    TREE root = NULL;

    FILE *fp = fopen("input.txt","w");

    srand(time(NULL));

    int i;

    for(i=0;i<9;i++)
    {
        random = rand()%100+1;
        fprintf(fp,"%d ",random);
    }
    fclose(fp);


    fp = fopen("input.txt","r");

    for(i=0;i<8;i++)
    {
        fscanf(fp,"%d",&n);
        root = insert(root,n);
    }

    inorder(root);

    c = count(root);

    printf("\nTotal leaf count %d",c);

}


