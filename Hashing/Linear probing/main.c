#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct hash
{
    int key;
    int value;
};

typedef struct hash Hash;

Hash hashTable[SIZE];

void initHashTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i].key = -1;
        hashTable[i].value = -1;
    }
}

int hashCode(int key)
{
    return key % SIZE;
}

void insert(int key, int value)
{
    int index = hashCode(key);

    while (hashTable[index].key != -1)
    {
        index = (index + 1) % SIZE;
    }

    hashTable[index].key = key;
    hashTable[index].value = value;
}

int search(int key)
{
    int index = hashCode(key);

    while (hashTable[index].key != -1)
    {
        if (hashTable[index].key == key)
        {
            return hashTable[index].value;
        }
        index = (index + 1) % SIZE;
    }

    return -1;
}

void displayHashTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("Index %d: ", i);
        if (hashTable[i].key == -1)
        {
            printf("Empty\n");
        }
        else
        {
            printf("%d -> %d\n", hashTable[i].key, hashTable[i].value);
        }
    }
}

int main()
{
    initHashTable();

    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    int key, value;
    while (fscanf(inputFile, "%d %d", &key, &value) != EOF)
    {
        insert(key, value);
    }

    fclose(inputFile);

    // Search elements
    int key1 = 30;
    int key2 = 40;
    int key3 = 70;

    int value1 = search(key1);
    int value2 = search(key2);
    int value3 = search(key3);

    printf("Value of key %d: %d\n", key1, value1);
    printf("Value of key %d: %d\n", key2, value2);
    printf("Value of key %d: %d\n", key3, value3);

    // Display hash table
    displayHashTable();

    return 0;
}
