#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

struct queue
{
    int data[SIZE];
    int front,rear;
};

void enqueue(int n,struct queue*qptr)
{
    if(qptr->rear == SIZE-1)
    {
        printf("Queue overflow.");
        exit(0);
    }
    else
    {
        qptr->rear++;
        qptr->data[qptr->rear] = n;
    }
}

int dequeue(struct queue*qptr)
{
    int n=0;
    if(qptr->rear == qptr->front)
    {
        printf("Queue empty.");
        exit(0);
    }
    else
    {
        qptr->front++;
        n = qptr->data[qptr->front];
    }
    return n;
}

int main()
{
    int choice,n;
    int i=0;
    struct queue*qptr,q;
    qptr = &q;
    qptr->front = -1;
    qptr->rear = -1;

    FILE*fp;

    fp = fopen("input.txt","r");

    while(1)
    {
        printf("enter your choice:\n");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                fscanf(fp,"%d",&n);
                enqueue(n,qptr);
                printf("Enqueued %d\n",n);
                break;
            case 2:
                n = dequeue(qptr);
                printf("Dequeued : %d\n",n);
                break;
            case 3:
                for(i = qptr->front ; i <= qptr->rear ; i++)
                {
                    printf("%d ",qptr->data[i]);
                }
                break;
            case 4:
                exit(0);

        }
    }
    fclose(fp);
    return 0;
}
