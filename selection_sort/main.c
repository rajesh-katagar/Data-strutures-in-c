#include <stdio.h>

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selectionsort(int a[],int n)
{
    int i,j,min;

    for(i=0;i<n-1;i++)
    {
        min = i;

        for(j=i+1 ; j<n ; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }
        if(min!= i)
        {
            swap(&a[i],&a[min]);
        }
    }
}



int main()
{
    int n,a[15],i;
    FILE *fp1;
    FILE *fp2;

    fp1 = fopen("input.txt","r");
    fscanf(fp1,"%d",&n);

    for(i=0;i<n;i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }

    printf("\n");

    fclose(fp1);

    selectionsort(a,n);

    fp2 = fopen("output.txt","w");
    for(i=0;i<n;i++)
    {
        fprintf(fp2,"%d ",a[i]);
    }

    return 0;
}
