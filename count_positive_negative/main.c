#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node* link;
};

typedef struct node* NODE;

NODE create_node(int value) {
    NODE newnode = (NODE)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory not allocated.\n");
        exit(1);
    }
    newnode->num = value;
    newnode->link = NULL;
    return newnode;
}

NODE insert_end(NODE head, int value) {
    NODE newnode = create_node(value);
    if (head == NULL) {
        return newnode;
    }
    NODE cur = head;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = newnode;
    return head;
}

void display(NODE head) {
    NODE cur = head;
    if (cur == NULL) {
        printf("Empty list.\n");
        return;
    }
    while (cur != NULL) {
        printf("%d ", cur->num);
        cur = cur->link;
    }
    printf("\n");
}

int main() {
    int n, i, a;
    FILE* fp = fopen("input.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);
    fprintf(fp, "%d\n", n);
    for (i = 0; i < n; i++) {
        a = rand() % 201 - 100;
        fprintf(fp, "%d\n", a);
    }
    fclose(fp);

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fscanf(fp, "%d", &n);

    NODE head = NULL;
    NODE poslink = NULL;
    NODE neglink = NULL;

    while (fscanf(fp, "%d", &a) != EOF) {
        head = insert_end(head, a);
        if (a >= 0) {
            poslink = insert_end(poslink, a);
        } else {
            neglink = insert_end(neglink, a);
        }
    }

    printf("Reference list: ");
    display(head);
    printf("Positive list: ");
    display(poslink);
    printf("Negative list: ");
    display(neglink);

    fclose(fp);
    return 0;
}
