#include<stdio.h>

typedef struct students
{
    char name[20];
    int roll_no;
    float sgpa;
}STUD;

void read(STUD s1[20],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter Student name:\n");
        scanf("%s",s1[i].name);
        printf("Enter Roll number:\n");
        scanf("%d",&s1[i].roll_no);
        printf("Enter sgpa:\n");
        scanf("%f",&s1[i].sgpa);
    }
}

void display(STUD s1[20],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("NAME\tROLL NUMBER\tSGPA\n");
        printf("%s\t%d\t%.2f\n",s1[i].name,s1[i].roll_no,s1[i].sgpa);
    }
}

int main()
{
    STUD s1[20];
    int n;
    printf("Enter number of students\n");
    scanf("%d",&n);
    read(s1,n);
    display(s1,n);
    return 0;
}