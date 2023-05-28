#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data[20];
    int top;
};

void push(int num,struct stack *sptr)
{
    if(sptr->top==19)
    {
        printf("Stack overflow\n");
        exit(0);
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=num;
    }
}

int pop(struct stack *sptr)
{
    int num=0;
    if(sptr->top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        num=sptr->data[sptr->top];
        sptr->top--;
    }
    return num;
}

int peek(struct stack *sptr)
{
    int num=0;
    if(sptr->top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        num=sptr->data[sptr->top];
    }
    return num;
}

int main()
{
    FILE *fp1,*fp2;

    struct stack s1;
    struct stack *sptr;
    int n,num1;
    sptr=&s1;
    sptr->top=-1;

    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    fscanf(fp1,"%d",&n);

    for(int i=0;i<n;i++)
    {
       fscanf(fp1,"%d",&num1);
       printf("%d ",num1);
       push(num1,sptr);
    }
    printf("\n");

    for(int i=0;i<n;i++)
    {
        num1=2*peek(sptr);
        fprintf(fp2,"%d ",num1);
        printf("%d ",num1);
        num1=pop(sptr);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}