#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[20],n,temp,i=0,j;
    FILE *fp1,*fp2;

    fp1 = fopen("bubble.txt","r");

    if(fp1 == NULL)
    {
        printf("File does not exist.");
        exit(0);
    }

    fscanf(fp1,"%d",&n);

    for(i=0;i<n;i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    fclose(fp1);

    fp2 = fopen("output.txt","w");
    if(fp2==NULL)
    {
        exit(0);
    }
    for(i=0;i<n;i++)
    {
        fprintf(fp2," %d ",a[i]);
    }
    fclose(fp2);
    return 0;
}
