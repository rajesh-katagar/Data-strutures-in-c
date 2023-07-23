#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node *NODE;

NODE createNode()
{
    NODE newNode = (NODE)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.");
        exit(0);
    }

    scanf("%d",&newNode->data);
    newNode->link = NULL;
    return newNode;
}

NODE insertFront(NODE head, int height)
{
    NODE newNode = createNode();

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->link = head;
        head = newNode;
    }
    return head;
}

NODE insertEnd(NODE head, int height)
{
    NODE newNode = createNode();

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        NODE cur = head;
        while(cur->link!=NULL)
        {
            cur = cur->link;
        }
        cur->link = newNode;
    }
    return head;
}

int countRepeatedHeights(NODE head)
{
    int count = 0;
    if (head == NULL)
    {
        return count;
    }

    NODE cur = head;
    while (cur != NULL)
    {
        int height = cur->data;
        NODE nextNode = cur->link;
        while (nextNode != NULL)
        {
            if (nextNode->data == height)
            {
                count++;
                break;
            }
            nextNode = nextNode->link;
        }
        cur = cur->link;
    }
    return count;
}

void displayList(NODE head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    NODE cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->link;
    }
    printf("\n");
}


int main()
{
    int n, height;
    NODE head = NULL;

    printf("Enter the number of heights: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &height);

        if (head == NULL)
        {
            head = createNode(height);
        }
        else
        {
            if (height < head->data)
            {
                head = insertFront(head, height);
            }
            else
            {
                head = insertEnd(head, height);
            }
        }
    }

    printf("List of heights: ");
    displayList(head);

    int repeatedCount = countRepeatedHeights(head);
    printf("Repeated heights count: %d\n", repeatedCount);

    free(head);
    return 0;
}
