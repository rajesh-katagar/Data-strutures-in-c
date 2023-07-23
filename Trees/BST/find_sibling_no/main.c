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
    else
    {
        newnode->data = n;
        newnode->rchild = newnode->lchild = NULL;
    }
    return newnode;
}

TREE insert(TREE root,int n)
{
    if(root == NULL)
        return create(n);

    else if( n > root->data )
        root->rchild = insert(root->rchild,n);
    else
        root->lchild = insert(root->lchild,n);
    return root;
}

int countSiblings(TREE root, int level, int data)
{
    if (root == NULL)
        return 0;

    if (level == 1)
    {
        // Count the number of siblings excluding the given data
        int count = 0;
        if (root->lchild && root->lchild->data != data)
            count++;
        if (root->rchild && root->rchild->data != data)
            count++;
        return count;
    }
    else if (level > 1)
    {
        int leftCount = countSiblings(root->lchild, level - 1, data);
        int rightCount = countSiblings(root->rchild, level - 1, data);
        return leftCount + rightCount;
    }

    return 0;
}
void inorder1(TREE root, int level)
{
    if (root != NULL)
    {
        inorder1(root->lchild, level + 1);
        printf("\n");
        printf(" %d (Level: %d) ", root->data, level);
        inorder1(root->rchild, level + 1);
    }
}


void inorder(TREE root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        printf(" %d ",root->data);
        inorder(root->rchild);
    }
}


int main()
{
    int i,random,n;
    FILE *fp;
    TREE root = NULL;

    fp = fopen("input.txt","w");

    if(fp == NULL)
        printf("File does not exist.");

    srand(time(NULL));

    for(i=0;i<9;i++)
    {
        random = rand()%100+1;
        fprintf(fp,"%d ",random);
    }
    fclose(fp);


    fp = fopen("input.txt","r");
    if(fp == NULL)
        exit(0);

    for(i=0;i<9;i++)
    {
        fscanf(fp,"%d",&n);
      root =  insert(root,n);
    }
     inorder(root);
   // inorder1(root, 1);
    printf("\n");
   // int siblingCount = countSiblings(root, 1, -1);
   //printf("Number of siblings at the same level: %d\n", siblingCount);


    return 0;
}
