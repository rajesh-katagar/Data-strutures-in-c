#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 12
int top=-1;
int stack[MAX];
FILE* pu;
FILE* po;
FILE* oper;
FILE* ran;
FILE* stac;
void push()
{
    int elem;
   fscanf(ran,"%d",&elem);
   fprintf(pu,"%d\n",elem);
   fprintf(oper,"%d is pushed\n",elem);
    stack[++top]=elem;
}
void pop()
{
    printf("%d is poped\n",stack[top]);
    fprintf(po,"%d\n",stack[top]);
    fprintf(oper,"%d is poped\n",stack[top]);
    top--;
}
void display()
{
    for (int i=0;i<=top;i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
void push_b()
{
    for(int i=0;i<=top;i++)
    {
        fprintf(stac,"%d\n",stack[i]);
    }
}
int main()
{
    int NUM1,NUM2,SIZE;
pu=fopen("push1.txt","a");
po = fopen( "pop1.txt" ,"a");
oper=fopen("operation1.txt","a");
stac=fopen("stack1.txt","r+");
ran=fopen("random1.txt","r+");
printf("ENTER THE NUMBER(NO OF RANDOM NUMBERS) AND RANGE OF RANDOM NUMBERS\n");
scanf("%d %d %d",&NUM1,&NUM2,&SIZE);

  srand(time(NULL));
  for(int i=0;i<SIZE;i++)
  {
      fprintf(ran,"%d\n",(rand()%NUM2)+NUM1);
  }
  rewind(ran);
    printf("THESE ARE STACK BASIC OPERATIONS\n");
    int oper;


while(1)
{
        printf("ENTER YOUR CHOICE\n1:PUSH\n2:POP\n3:DISPLAY\n4:exit\n");
        scanf("%d",&oper);
        switch(oper)
        {

        case 1 :
            push();
            break;
        case 2 :
            pop();
            break;

        case 3 :
            display();
            break;
        case 4 :
            push_b();
            exit(0);
            break;

        default:
            printf("ENTER THE VALID CHOICE\n");
        }
}
}