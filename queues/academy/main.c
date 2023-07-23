#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

struct queue
{
    int data[SIZE];
    int front,rear;
};

void enqueue(int n, struct queue *qptr)
{
    if (qptr->rear == SIZE - 1 && qptr->front == -1)
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


int dequeue(struct queue *qptr)
{
    int n = 0;

    if (qptr->rear == qptr->front && qptr->front != -1)
    {
        printf("Queue underflow.");
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
    int i=0,n=0,num=0,count=0;
    struct queue*qptr,q;
    qptr = &q;

    qptr->front = -1;
    qptr->rear = -1;

    printf("Enter n value\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        enqueue(num,qptr);
    }

    while(qptr->rear!=qptr->front)
    {
        num = dequeue(qptr);
        printf("%d ",num);
        if(num >= 185)
        {
            count++;
        }
    }
    printf("\n");
    printf("%d",count);

    return 0;
}


/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

struct queue
{
    int data[SIZE];
    int front,rear;
};

void enqueue(int n, struct queue *qptr)
{
    if (qptr->rear == SIZE - 1 && qptr->front == -1)
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


int dequeue(struct queue *qptr)
{
    int n = 0;

    if (qptr->rear == qptr->front && qptr->front != -1)
    {
        printf("Queue underflow.");
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
    int i=0,n=0,num=0,count=0;
    struct queue*qptr,q;
    qptr = &q;

    qptr->front = -1;
    qptr->rear = -1;

    FILE*fp;

    fp = fopen("input.txt","r");

    printf("Enter n value");
    fscanf(fp,"%d",&n);
   // printf("%d",n);

    for(i=0;i<n;i++)
    {
        fscanf(fp,"%d",&num);
        enqueue(num,qptr);
    }

    while(qptr->rear!=qptr->front)
    {
        num = dequeue(qptr);
        if(num >= 185)
        {
            count++;
            printf("%d",num);
        }
    }
    printf("%d",count);
    fclose(fp);
    return 0;
}
*/