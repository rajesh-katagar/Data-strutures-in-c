//SELECTION FOR INDIAN MILITARY.SELECT THE CANDIDATES WHOSE HEIGHT IS MORE THAN OR EQUAL TO 185 AND PRINT THEIR DETAILS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

struct candidate  //Candidate details
        {
            int height;
            char name[SIZE], place[SIZE], gender[SIZE];
        };

struct stack
        {
            struct candidate candidates[SIZE];
            int top;
        };

void push(struct stack *sptr, struct candidate c)
        {
            if (sptr->top == SIZE - 1)
            {
                printf("Stack overflow.");
                exit(0);
            }
            else
            {
                sptr->top++;
                sptr->candidates[sptr->top] = c;
            }
        }

struct candidate pop(struct stack *sptr)
        {
             struct candidate c;
                 if (sptr->top == -1)
                 {
                    printf("Stack underflow.");
                    exit(0);
                 }
                 else
                 {
                     c = sptr->candidates[sptr->top];
                     sptr->top--;
                 }
                      return c;
        }

int main()
{
    int n, count = 0;
    struct stack s;

    s.top = -1;
    char particular[SIZE];

    printf("Enter n value: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        struct candidate c;
        scanf("%d", &c.height);
        scanf("%s %s %s", c.name, c.place, c.gender);
        push(&s, c);
    }

    printf("Enter particular place: ");
    scanf("%s", particular);

    for (int i = 0; i < n; i++)
    {
        struct candidate c = pop(&s);
        if (c.height >= 185)  //check whether height is greater than or equal to 185
        {
            count++;
            if (strcmp(c.place, particular) == 0)
            {
                printf("%s %s %s %d\n", c.name, c.place, c.gender, c.height);
            }
        }
    }

    printf("Number of candidates with height more than 185cm: %d\n", count);

    return 0;
}



/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

struct stack
{
    int height[SIZE];
    char name[SIZE],place[SIZE],gender[SIZE];
    int top;
};

void push(struct stack*sptr,int n)
{
    if(sptr->top == SIZE-1)
    {
        printf("Stack overflow.");
        exit(0);
    }
    else
    {
        sptr->top++;
        sptr->height[sptr->top] = n;
    }
}

int pop(struct stack*sptr)
{
    int n=0;
    if(sptr->top == -1)
    {
        printf("Stack underflow.");
        exit(0);
    }
    else
    {
        n = sptr->height[sptr->top];
        sptr->top--;
    }
    return n;
}


int main()
{
    int n,count=0,h=0,num=0;
    struct stack*sptr,s;
    sptr = &s;
    sptr->top = -1;
    char particular[10];

    printf("Enter n value\n");
    scanf("%d",&n);

    for(int i =0;i<n;i++)
    {
        scanf("%d",&num);
        scanf("%s %s %s",sptr->name,sptr->place,sptr->gender);
        push(sptr,num);
    }

    printf("Enter particular place\n");
    scanf("%s",particular);

    for(int i=0;i<n;i++)
    {
        h = pop(sptr);
        if(h >= 185)
        {
            count++;
            scanf("%s %s %s",sptr->name,sptr->place,sptr->gender,&sptr->height);
        }
        if(strcmp(sptr->place,particular)==0)
        {
            printf("%s %s %s",sptr->name,sptr->place,sptr->gender,sptr->height);
        }
    }

    printf("%d",count);

    return 0;
}
*/
