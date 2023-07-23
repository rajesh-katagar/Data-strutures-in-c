/*NAME:RAJESH KATAGAR
DIV-E ROLL NO-514
USN-01FE21BEC257
PROGRAM-SUM OF N NUMBERS
TIME COMPLEXITY-O(n)
*/
#include <stdio.h>

int sumofn(int n)
{
    int sum = 0,i;
    for(i=0;i<=n;i++)
    {
        sum = sum + i;
    }
    return sum;
}

int main()
{
    int n,s;
    printf("Enter the n value\n");
    scanf("%d",&n);

    s = sumofn(n);
    printf("The sum is %d",s);
    return 0;
}