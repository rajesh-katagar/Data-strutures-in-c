#include <stdlib.h>
#include <stdio.h>

#define SIZE 10

struct hash
{
    int data;
    struct hash* link;
};

typedef struct hash* HASH;

struct hashtable
{
    HASH* table;
};


HASH create(int data)
{
    HASH newnode = (HASH)malloc(sizeof(struct hash));

    if (newnode == NULL)
        exit(0);
    else
    {
        newnode->data = data;
        newnode->link = NULL;
    }
    return newnode;
}

struct hashtable* createtable()
{
    struct hashtable* tables = (struct hashtable*)malloc(sizeof(struct hashtable));
    tables->table = (HASH*)malloc(SIZE * sizeof(HASH));

    for (int i = 0; i < SIZE; i++)
    {
        tables->table[i] = NULL;
    }
    return tables;
}

void insert(struct hashtable* hashTable, int key)
{
    int index = key % SIZE;
    HASH newNode = create(key);

    if (hashTable->table[index] == NULL)
    {
        hashTable->table[index] = newNode;
    }
    else
    {
        HASH currentNode = hashTable->table[index];
        while (currentNode->link != NULL)
        {
            currentNode = currentNode->link;
        }
        currentNode->link = newNode;
    }
}

void  display(struct hashtable*hashtab)
{
    for(int i=0;i<SIZE;i++)
    {
        printf("%d-> ",i);
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
    struct hashtable* hashTable = createtable();
    FILE*fp;

    fp = fopen("input.txt","r");


    if(fp == NULL)
        exit(0);
    int key;
    printf("Enter elements to insert into the hash table (enter -1 to stop):\n");
    while (1)
    {
        fscanf(fp,"%d",&key);
        if (key == -1)
            break;
        insert(hashTable, key);
    }

    // Print hash table
    display(hashTable);

    return 0;
}
