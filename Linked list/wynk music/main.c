#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char song[20], singer[20];
    float duration;
    int year;
    struct node *rightlink;
    struct node *leftlink;
};

typedef struct node *NODE;

NODE create_node()
{
    NODE newnode = (NODE)malloc(sizeof(struct node));

    if (newnode == NULL)
        exit(0);
    else
    {
        scanf("%s %s %f %d", newnode->song, newnode->singer, &newnode->duration, &newnode->year);
        newnode->rightlink = NULL;
        newnode->leftlink = NULL;
    }
    return newnode;
}

NODE insert_end(NODE head)
{
    NODE newnode, cur;
    newnode = create_node();

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        cur = head;
        while (cur->rightlink != NULL)
        {
            cur = cur->rightlink;
        }
        cur->rightlink = newnode;
        newnode->leftlink = cur;
    }
    return head;
}

void display(NODE head, FILE *fp)
{
    NODE cur;
    if (head == NULL)
        exit(0);
    else
    {
        cur = head;
        while (cur != NULL)
        {
            fprintf(fp, "%s %s %.2f %d\n", cur->song, cur->singer, cur->duration, cur->year);
            cur = cur->rightlink;
        }
    }
}

void display_singer(NODE head, FILE *fp)
{
    NODE cur;
    int status = 0;
    char particular[20];

    printf("\n");

    scanf("%s", particular);
    if (head == NULL)
        exit(0);
    else
    {
        cur = head;
        while (cur != NULL)
        {
            if (strcmp(particular, cur->singer) == 0)
            {
                fprintf(fp, "%s %s %.2f %d\n", cur->song, cur->singer, cur->duration, cur->year);
                status = 1;
            }
            cur = cur->rightlink;
        }
    }
    if (status == 0)
    {
        fprintf(fp, "No songs of %s to display\n", particular);
    }
}

void search_and_delete(NODE head)
{
    char key[20];
    NODE cur, prev, next;
    int status = 0;
    scanf("%s", key);

    if (head == NULL)
    {
        status = 1;
        exit(0);
    }
    else if (strcmp(head->song, key) == 0)
    {
        printf("\nDeleted : %s %s %.2f %d\n", head->song, head->singer, head->duration, head->year);
        next = head->rightlink;
        head = next;
        free(head);
        status = 1;
    }
    else
    {
        cur = head;
        while (cur->rightlink != NULL)
        {
            prev = cur;
            next = cur->rightlink;
            if (strcmp(cur->song, key) == 0)
            {
                printf("\nDeleted %s %s %.2f %d", cur->song, cur->singer, cur->duration, cur->year);
                prev->rightlink = next;
                next->leftlink = prev;
                cur->rightlink = cur->leftlink = NULL;
                free(cur);
                status = 1;
            }
            cur = cur->rightlink;
        }
        if (strcmp(cur->song, key) == 0)
        {
            printf("\nDeleted %s %s %.2f %d", cur->song, cur->singer, cur->duration, cur->year);
            prev->rightlink = NULL;
            free(cur);
            status = 1;
        }
    }
    printf("\n");
    if (status == 0)
        printf("No song %s to delete", key);
}

int main()
{
    int n, i;
    NODE head = NULL;

    FILE *fp = fopen("input.txt", "r");

    if (fp == NULL)
        exit(0);
    fscanf(fp, "%d", &n);

    for (i = 0; i < n; i++)
    {
        head = insert_end(head);
    }
    display(head, fp);
    display_singer(head, fp);
    search_and_delete(head);

    fclose(fp);
    return 0;
}
