#include<stdio.h>

#define size 10
struct stack
{
    int data[size];
    int top;
};


void push(struct stack * sptr,int num,FILE *fp)
{
    if(sptr->top==size-1)
    {
        printf("Stack overflow");
    }
    else
    {
        sptr->top++;
        fscanf(fp,"%d",&sptr->data[sptr->top]);
    }}

int pop(struct stack *sptr)
{
    int num;
    if(sptr->top==-1)
    {
        printf("stack underflow");
    }
    else
    {
        num=sptr->data[sptr->top];
        sptr->top--;
    }
    return num;
}

int peak(struct stack* sptr)
{
    int num;
    if(sptr->top==-1)
    {
        printf("Stack empty");
    }
    else
    {
        num=sptr->data[sptr->top];

    }
    return num;
}

void display(struct stack *sptr)
{
    int i;
    if(sptr->top==-1)
    {

        printf("Stack empty");

    }
    else
    {

        for(i=sptr->top;i>=0;i--)
        {
            printf("%d ",sptr->data[i]);
        }
    }
}

int main()
{
    int ch,num;
    struct stack *sptr;
    sptr->top=-1;
    FILE *fp;
    fp=fopen("input.txt","r");
    printf("1->push\n2->pop\n3->display");
    while(1)
    {
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push(sptr,num,fp);
                break;
            case 2:num=pop(sptr);
                break;
            case 3:num=peak(sptr);
                printf("peak=%d\n",num);
                break;
            case 4:display(sptr);
                printf("\n");
                break;
            default:printf("Invalid ");
                break;
        }
    }
    fclose(fp);
}