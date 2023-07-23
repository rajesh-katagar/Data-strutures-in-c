#include <stdio.h>

int find_max(int arr[], int n)
{
    int max = arr[0];
    for (int i=1; i<n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;
    int arr[10];

    FILE *fp1;
    FILE *fp2;

    fp1 = fopen("input.txt","r");

    fscanf(fp1,"%d",&n);
    for(int i=0; i<n ;i++)
    {
        fscanf(fp1,"%d",&arr[i]);
    }
    int max = find_max(arr, n);
    fclose(fp1);

    fp2 = fopen("output.txt","w");

    fprintf(fp2,"The maximum value in the array is: %d\n", max);

    fclose(fp2);

    return 0;
}