#include <stdio.h>

/*
int power(int m,int n)
{
    if(n==0)
        return 1;
    else
        return power(m,n-1)*m;
}
*/

int power(int m,int n)
{
    if(n==0)
        return 1;
    if(n%2 == 0)
        return power(m*m,n/2);
    else
        return m* power(m*m,(n-1)/2);
}

int main()
{
    int n,m;
    printf("Enter the number\n");
    scanf("%d",&m);
    printf("Enter it's power\n");
    scanf("%d",&n);

    int s;

    s = power(m,n);

    printf("Result:%d",s);

    return 0;
}


