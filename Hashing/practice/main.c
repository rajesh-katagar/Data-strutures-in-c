#include <stdio.h>
#include<stdlib.h>
#define SIZE 9

struct hash
{
    int data;
    struct hash*link;
};

typedef struct hash*HASH;

struct hashtable
{
    HASH *table;
};

HASH create(int data)
{
    HASH newnode = (HASH) malloc(sizeof(struct hash));
    if(newnode == NULL)
        exit(0);
    else
    {
        newnode->data = data;
        newnode->link = NULL;
    }
    return newnode;
}

struct hashtable*createtable()
{
    struct hashtable*hashtab = (struct hashtable*) malloc(sizeof(struct hashtable));
    hashtab->table = (HASH*) malloc(SIZE*sizeof(HASH));

    for(int i = 0 ; i < SIZE ; i++)
        hashtab->table[i] = NULL;//initialise whole table to NULL

    return hashtab;
}

void insert(struct hashtable*hashtab,int key)
{
    int i = key%SIZE;
    HASH newnode = create(key);

    if(hashtab->table[i] == NULL)
        hashtab->table[i] = newnode;
    else
    {
        HASH cur = hashtab->table[i];
        while(cur->link!=NULL)
            cur = cur->link;

        cur->link = newnode;
    }
}

void display(struct hashtable*hashtab)
{
    for(int i=0;i<SIZE;i++)
    {
        printf("%d->",i);
        HASH cur = hashtab->table[i];
        while(cur!=NULL)
        {
            printf("%d ",cur->data);
            cur = cur->link;
        }
        printf("\n");
    }
}

int main()
{
    struct hashtable*hashtab = createtable();
    FILE*fp = fopen("input.txt","r");
    if(fp == NULL)
        exit(0);
    int key;

    while(1)
    {
        fscanf(fp,"%d",&key);
        if(key == -1)
            break;
        else
            insert(hashtab,key);
    }

    display(hashtab);

    return 0;
}
