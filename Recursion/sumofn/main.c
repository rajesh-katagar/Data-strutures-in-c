#include <stdio.h>

int sum(int n)
{
    if(n == 0)
        return 0;
    else
        return (sum(n-1)+n);
}

int main()
{
    int n,s;
    printf("Enter n value\n");
    scanf("%d",&n);

    s = sum(n);

    printf("Sum of %d numbers is %d",n,s);

    return 0;
}
