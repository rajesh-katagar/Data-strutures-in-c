/*
 ITERATIVE ALGORITHMS
NAME:RAJESH KATAGAR
DIV - E  ROLL NUMBER - 514
PROGRAM - LINEAR SEARCH OF N NUMBERS
TIME COMPLEXITY - O(n)
*/
#include <stdio.h>

//Function to check whether given number is present in array or not
void linearsearch(int a[20],int n)
{
    int i,search;

    printf("Enter the element to be searched\n");
    scanf("%d",&search);

    for(i=0;i<n;i++)
    {
        if(search == a[i])
        {
            printf("%d is present in array at the location %d",search,i+1);
        }
    }
    if(i == n)
    {
        printf("%d is not present in the array",search);
    }

}

int main()
{
    int n,i,a[20];

    printf("Enter the of elements in the array\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");

    linearsearch(a,n);

    return 0;

}