#include <stdio.h>
#include <stdlib.h>

int repeated(int a[20],int n)
{
    int i,j,count=0,status=0;

    for (i= 0; i < n; i++)
    {
        count =1;
        for(j=i+1;j<n;j++)
        {
            if(a[j] > 0)
            {
                if(a[i] == a[j])
                {
                    count++;
                    a[j] = -1;
                    break;
                }
            }
            else
            {
                status = 1;
                break;
            }
        }

        if(count > 1)
            printf("%d is repeated %d times\n",a[i],count);

    }
    if(status == 1)
    {
        printf("Enter positive numbers.");
        exit(0);
    }

    return count;
}
int main()
{
    int a[20],n,i,s;
    FILE *fp;

    fp = fopen("input.txt","r");
    if(fp == NULL)
        printf("File does not exist.");

    fscanf(fp,"%d",&n);

    for(i=0;i<n;i++)
    {
        fscanf(fp,"%d",&a[i]);
    }


    s = repeated(a,n);

    printf("Duplicated element count:%d",s);

    return 0;
}
