/*
RECURSIVE ALGORITHM
NAME:RAJESH KATAGAR
DIV - E  ROLL NUMBER - 514
PROGRAM - FIBONACCI SERIES
TIME COMPLEXITY - O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return (fibonacci(n-1)+ fibonacci(n-2));
}

int main()
{
    int i,n;

    FILE *fp1;
    FILE *fp2;

    fp1 = fopen("fact.txt","r");
    fp2 = fopen("output.txt","w");

    fscanf(fp1,"%d",&n);

    fclose(fp1);

    for(i=0;i<n;i++)
    {
       fprintf(fp2,"%d ", fibonacci(i));
    }

    return 0;
}
