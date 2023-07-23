#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tree
{
    int data;
    struct tree *rchild;
    struct tree *lchild;
};

typedef struct tree *TREE;

TREE create(int n)
{
    TREE newnode = (TREE)malloc(sizeof(struct tree));
    if (newnode == NULL)
        exit(0);
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
        return create(n);

    else if (n > root->data)
        root->rchild = insert(root->rchild, n);
    else
        root->lchild = insert(root->lchild, n);
    return root;
}

void inorder(TREE root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        printf(" %d ", root->data);
        inorder(root->rchild);
    }
}

int countSiblings(TREE root, int level, int data)
{
    if (root == NULL)
        return 0;

    if (level == 1)
    {
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

int main()
{
    int i, n, level = 0, count, c;
    FILE *fp;
    TREE root = NULL;

    fp = fopen("input.txt", "w");

    if (fp == NULL)
    {
        printf("File does not exist.");
        return 0;
    }

  //  srand(time(NULL));
    for (i = 0; i < 7; i++)
    {
        int random = rand() % 100;
        fprintf(fp, "%d\n", random);
    }
    fclose(fp);

    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("File does not exist.");
        return 0;
    }

    while (fscanf(fp, "%d", &n) != EOF)
    {
        root = insert(root, n);
        printf(" %d ", n);
    }
    printf("\n");
    fclose(fp);

    inorder(root);
    printf("\n");

    for (i = 0; i < 20; i++)
    {
        level = level + 1;
        count = countSiblings(root, level, 1234567);
        printf("Number of siblings at level %d: %d\n", level, count);
    }

    return 0;
}
