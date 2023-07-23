#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tree {
    int data;
    struct tree* rchild;
    struct tree* lchild;
};

typedef struct tree* TREE;

TREE create_node(int data) {
    TREE newnode = (TREE)malloc(sizeof(struct tree));
    if (newnode == NULL)
        exit(0);
    else {
        newnode->data = data;
        newnode->rchild = newnode->lchild = NULL;
    }
    return newnode;
}

TREE insert(TREE root, int data)
{
    if (root == NULL)
        root = create_node(data);
    else if (root->data >= data)
    {
        root->lchild = insert(root->lchild, data);
    }
    else
    {
        root->rchild = insert(root->rchild, data);
    }
    return root;
}

void inorder(TREE root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

TREE search(TREE root,int key)
{
    TREE cur = root;

    if(cur == NULL)
        return NULL;
    if(key == cur->data)
        return cur;
    else if(key < cur->data)
        return search(cur->lchild,key);
    else
        return search(cur->rchild,key);
}



/*int Height(TREE root)
{
    int x, y;
    if (root == NULL)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}*/

TREE InPre(TREE root)
{
    while (root && root->rchild != NULL)
        root = root->rchild;
    return root;
}

TREE InSucc(TREE root)
{
    while (root && root->lchild != NULL)
        root = root->lchild;
    return root;
}

TREE deleteNode(TREE root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->lchild = deleteNode(root->lchild, data);
    else if (data > root->data)
        root->rchild = deleteNode(root->rchild, data);
    else {
        if (root->lchild == NULL && root->rchild == NULL)//if it is leaf node
        {
            free(root);
            root = NULL;
        }
        else if (root->lchild == NULL)//if it has no left child
        {
            TREE temp = root;
            root = root->rchild;
            free(temp);
        }
        else if (root->rchild == NULL)//if it has no right child
        {
            TREE temp = root;
            root = root->lchild;
            free(temp);
        }
        else//if it has both
        {
            TREE temp = InPre(root->lchild);//insucc function can also be used.
            root->data = temp->data;
            root->lchild = deleteNode(root->lchild, temp->data);
        }
    }

    return root;
}


int main()
{
    int x;

    TREE root = NULL;
    int key,delete;
    int i;

    FILE*fp = fopen("input.txt","w");

    srand(time(NULL));//generates suddenly

    if(fp == NULL)
        exit(0);

    for(i=0;i<6;i++)
    {
        int random = rand()%101 + 100;//generates numbers from 1 to 100
        fprintf(fp,"%d ",random);
    }

    fclose(fp);

    fp = fopen("input.txt","r");

    if(fp == NULL)
        exit(0);

    for (i = 0; i < 5; i++)
    {
        fscanf(fp,"%d",&x);
        root = insert(root, x);
        printf("Inorder traversal after inserting %d: ", x);
        inorder(root);
        printf("\n");
    }
    fscanf(fp,"%d",&key);

    printf("Enter element to be deleted\n");
    scanf("%d",&delete);
    root = deleteNode(root, delete);
    inorder(root);

    root = search(root,key);

    if(root == NULL)
    {
        printf("\n%d not found in tree",key);
    }
    else
    {
        printf("\n%d found in tree",key);
    }

    fclose(fp);
    return 0;
}
