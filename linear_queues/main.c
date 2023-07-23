#include<stdio.h>
#include<time.h>
#define size 10
struct queue
{
    int data[size];
    int front,rear;
};

void random(FILE *fp)
{
    for(int i=0;i<size;i++)
    {
        fprintf(fp,"%d ",rand()%100);
    }
}

void enqueue(struct queue*qptr,FILE *fp1)
{
    if(qptr->rear==size-1)
    {
        printf("Queue full");
    }
    else
    {
        qptr->rear++;
        fscanf(fp1,"%d",&qptr->data[qptr->rear]);
    }
}

void dequeue(struct queue *qptr)
{
    if((qptr->front==-1&&qptr->rear==-1)||(qptr->front==qptr->rear))
    {
        printf("Queue Empty\n");
    }
    else

    {
        qptr->front++;
    }

}

void disp(struct queue *qptr)
{
    if((qptr->front==-1&&qptr->rear==-1)||(qptr->front==qptr->rear))
    {
        printf("Queue Empty\n");
    }
    for(int i=qptr->front+1;i<=qptr->rear;i++)
    {
        printf("%d ",qptr->data[i]);
    }
}

void main()
{
    struct queue *qptr;
    struct queue q[10];
    qptr=q;
    qptr->front=qptr->rear=-1;
    int c;
    FILE *fp=fopen("b.txt","w+");
    random(fp);
    rewind(fp);
    fp=fopen("b.txt","r");
    printf("1->enqueue\n2->dequeue\n3->display");
    while(1)
    {
        printf("\nEnter choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:enqueue(qptr,fp);
                break;
            case 2:dequeue(qptr);
                break;
            case 3:printf("\nThe contents of the queue are:\n");
                disp(qptr);
                printf("\n");
                break;
        }

    }
    fclose(fp);
}