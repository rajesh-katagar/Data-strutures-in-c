/*NAME:RAJESH KATAGAR
DIV - E  ROLL NUMBER - 514
PROGRAM - FACTORIAL OF A NUMBER
TIME COMPLEXITY - O(n)
*/


#include <stdio.h>

int factorial(int n)
{
    if(n == 0)
        return 1;//base condition 1
    else if(n == 1)
        return 1;//base condition 2
    else
        return (n*factorial(n-1));
}

int main()
{
    int i,n,fact;
    printf("Enter the number\n");//number of which factorial has to be found out
    scanf("%d",&n);

    fact = factorial(n);

    printf("Factorial is %d\n",fact);

    return 0;
}
