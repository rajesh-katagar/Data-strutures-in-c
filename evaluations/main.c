#include<stdio.h>
#include<time.h>
#define size 10
struct stack
{
    int data[size];
    int top;
};

void push(struct stack *sptr,FILE *fp)
{ while(!feof(fp))
    {
        sptr->top++;
        fscanf(fp,"%d",&sptr->data[sptr->top]);
    }
}
void pop(struct stack *sptr,FILE *fp)
{
    while(sptr->top!=0)
    {
        sptr->top--;
        fprintf(fp,"%d ",2*sptr->data[sptr->top]);
    }
}
void main()
{
    struct stack *sptr;
    struct stack s;
    srand(time(NULL));
    sptr=&s;
    sptr->top=-1;
    FILE *fp1=fopen("in.txt","w+");
    FILE *fp2=fopen("out.txt","w");
    sptr->top=-1;
    push(sptr,fp1);
    pop(sptr,fp2);

}