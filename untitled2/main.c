#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

typedef struct node* NODE;

NODE create_node() {
    NODE newnode;
    newnode = (NODE) malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }
    else {
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->link = NULL;
    }
    return newnode;
}

NODE insert_end(NODE head) {
    NODE newnode, cur;

    newnode = create_node();

    if (head == NULL) {
        head = newnode;
    }
    else {
        cur = head;
        while (cur->link!= NULL) {
            cur = cur->link;
        }
        cur->link = newnode;
    }

    return head;
}

void display_recursion(NODE head)
{
    if (head != NULL)
    {
        printf("%d ", head->data);
        display_recursion(head->link);
    }
}

int count(NODE head)
{
    int c = 0;
    NODE cur = head;

    while (cur != NULL)
    {
        c++;
        cur = cur->link;
    }

    return c;
}

int add(NODE head)
{
    if(head == NULL)
        return 0;
    else
        return add(head->link)+head->data;
}

int searched(NODE head, int search)
{
    if (head == NULL)
        return 0;
    else
    {
        if (search == head->data)
            return 1;
        else
            return searched(head->link, search);
    }
}

NODE insert_position(NODE head, int pos) {
    NODE newnode = create_node();

    if (pos == 0)
    {
        newnode->link = head;
        head = newnode;
    }
    else
    {
        NODE cur = head;
        for (int i = 0; i < pos - 1 && cur; i++)
        {
            cur = cur->link;
        }

        if (cur!=NULL)
        {
            newnode->link = cur->link;
            cur->link = newnode;
        }
        else
        {
            // Handle the case when pos is greater than the length of the linked list
            // You can choose to display an error message or adjust the position to insert at the end
            // For example, you can modify pos = length of the linked list to insert at the end
            printf("Invalid position!\n");
            // Or adjust pos = length of the linked list and call the function recursively
            // return insert_position(head, length_of_linked_list(head));
        }
    }

    return head;
}

NODE delete_front(NODE head)
{
    NODE cur;
    if(head == NULL)
        exit(0);
    else if(head->link == NULL)
    {
        printf("Deleted:%d\n",head->data);
        free(head);
        head = NULL;
    }
    else
    {
        cur = head;
        printf("Deleted : %d\n",head->data);
        head = head->link;
        cur->link = NULL;
        free(cur);
    }
    return head;
}

NODE delete_position(NODE head,int pos)
{
    NODE cur,prev=NULL;
    if(pos == 1)
    {
        head = delete_front(head);
    }
    else
    {
        cur = head;
        for(int i=0;i<pos-1&&cur;i++)
        {
            prev = cur;
            cur = cur->link;
        }
        if(cur!=NULL)
        {
            prev->link = cur->link;
            printf("Deleted:%d\n",cur->data);
            free(cur);
        }
        else
        {
            printf("Invalid position.");
        }
    }
    return head;
}


int check_sorted(NODE head)
{
    int x = -32678;

    NODE cur = head;

    while(cur!=NULL)
    {
        if(cur->data < x)
        {
            return 0;
        }
            x = cur->data;
            cur = cur->link;
    }
    return 1;
}

NODE remove_duplicates(NODE head)
{
    NODE cur,prev;
    prev = head;
    cur = head->link;

    while(cur!=NULL)
    {
        if(cur->data!= prev->data)
        {
            prev = cur;
            cur = cur->link;
        }
        else
        {
            prev->link = cur->link;
            free(cur);
            cur = NULL;
            prev = cur->link;
        }
    }
}

int main() {
    int choice, co,sum=0,search=0,sort;
    NODE head = NULL;
    int pos=0,del=0;

    printf("Enter your choice\n");

    while (1)
    {
        printf("\n1: INSERT END 2: DISPLAY 3: COUNT 4: SUM 5:SEARCH "
               "6:INSERT POSITION 7:DELETE FRONT 8:DELETE POSITION 9:CHECK SORTED  10.DUPLICATES 11:EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                head = insert_end(head);
                break;
            case 2:
                display_recursion(head);
                break;
            case 3:
                co = count(head);
                printf("Total nodes: %d\n", co);
                break;
            case 4:
                sum = add(head);
                printf("Sum : %d\n",sum);
                break;
            case 5:
                printf("Enter element to be searched:\n");
                scanf("%d", &search);
                if (searched(head, search))
                    printf("%d found\n", search);
                else
                    printf("%d not found\n", search);
                break;
            case 6:
                printf("Enter at what position to be inserted(from 0)\n");
                scanf("%d",&pos);
                head = insert_position(head,pos);
                break;
            case 7:
                head = delete_front(head);
                break;
            case 8:
                printf("Enter the position where node has to be deleted(from 0)\n");
                scanf("%d",&del);
                head = delete_position(head,del);
                break;
            case 9:
                 sort = check_sorted(head);
                    if(sort == 0)
                    {
                        printf("Not sorted.");
                    }
                    else
                    {
                        printf("Sorted.");
                    }
                break;
            case 10:
                head = remove_duplicates(head);
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
