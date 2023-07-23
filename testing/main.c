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

/*void display_recursion(NODE head)
{
    if (head != NULL)
    {
        printf("%d ", head->data);
        display_recursion(head->link);
    }
}
*/
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

int main() {
    int choice, co;
    NODE head = NULL;

    printf("Enter your choice\n");
    printf("1: INSERT END 2: DISPLAY 3: COUNT 4: EXIT\n");

    while (1)
    {
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                head = insert_end(head);
                break;
            case 2:
               // display_recursion(head);
                break;
            case 3:
                co = count(head);
                printf("Total nodes: %d\n", co);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
