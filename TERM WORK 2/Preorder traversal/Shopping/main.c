#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[50];
    struct Item* next;
};

typedef struct Item* ITEM;

struct Category {
    char name[50];
    struct Category* next;
    struct Item* items;
};

typedef struct Category* CATEGORY;

CATEGORY createCategory(const char* name) {
    CATEGORY newCategory = (CATEGORY)malloc(sizeof(struct Category));
    if (newCategory == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    strcpy(newCategory->name, name);
    newCategory->next = NULL;
    newCategory->items = NULL;
    return newCategory;
}

ITEM createItem(const char* name) {
    ITEM newItem = (ITEM)malloc(sizeof(struct Item));
    if (newItem == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    strcpy(newItem->name, name);
    newItem->next = NULL;
    return newItem;
}

void preorderTraversal(CATEGORY category)
{
    if (category == NULL)
    {
        return;
    }

    printf("%s\n", category->name);

    ITEM item = category->items;
    while (item != NULL)
    {
        printf("%s\n", item->name);
        item = item->next;
    }

    preorderTraversal(category->next);
}

void freeMemory(CATEGORY category)
{
    if (category == NULL) {
        return;
    }

    ITEM currentItem = category->items;
    while (currentItem != NULL) {
        ITEM nextItem = currentItem->next;
        free(currentItem);
        currentItem = nextItem;
    }

    freeMemory(category->next);
    free(category);
}

int main()
{
    FILE* fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("File does not exist.");
        return 1;
    }

    CATEGORY head = NULL;
    CATEGORY currentCategory = NULL;

    char category[50];
    while (fscanf(fp, "%s", category) == 1)
    {

        if (currentCategory == NULL)
        {
            head = createCategory(category);
            currentCategory = head;
        }
        else
        {
            currentCategory->next = createCategory(category);
            currentCategory = currentCategory->next;
        }

        char item[50];
        while (fscanf(fp, "%s", item) == 1 && item[0] != '\0') {
            ITEM newItem = createItem(item);
            if (currentCategory->items == NULL) {
                currentCategory->items = newItem;
            }
            else
            {
                ITEM currentItem = currentCategory->items;
                while (currentItem->next != NULL)
                {
                    currentItem = currentItem->next;
                }
                currentItem->next = newItem;
            }
        }
    }

    fclose(fp);

    printf("Shopping List:\n");
    preorderTraversal(head);

    freeMemory(head);

    return 0;
}
