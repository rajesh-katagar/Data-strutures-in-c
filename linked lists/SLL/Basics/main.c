#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*link;
};

typedef struct node*NODE;

NODE create_node()
{
    NODE newnode;
    newnode = (NODE) malloc(sizeof(struct node));

    if(newnode == NULL)
        exit(0);
    else
    {
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        newnode->link = NULL;
    }
    return newnode;
}

void display(NODE head)
{
    if (head == NULL)
        return;

    display(head->link);//head recursion
    printf("%d ", head->data);
}

NODE reverse_list(NODE head)
{
    NODE cur = head;
    int i = 0;
    int a[10];
    while(cur!=NULL)
    {
        a[i] = cur->data;
        cur = cur->link;
        i++;
    }
    cur = head;
    i--;
    while(cur!=NULL)
    {
        cur->data = a[i--];
        cur = cur->link;
    }
    cur = head;

    while(cur!=head)
    {
        printf("%d",cur->data);
        cur = cur->link;
    }

    return head;
}


NODE insert_front(NODE head)
{
    NODE cur = head;
    NODE newnode = create_node();
    if(head == NULL)
        head = newnode;
    else
    {
        newnode->link = head;
        head = newnode;
    }
    return head;
}

int main()
{
    int choice;
    NODE head=NULL;
    while(1)
    {
        printf("\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:head = insert_front(head);
                break;
            case 2:
                display(head);
            case 3:head = reverse_list(head);
                break;
        }

    }

    return 0;
}
