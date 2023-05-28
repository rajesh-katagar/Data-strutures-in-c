#include <stdio.h>
#include <stdlib.h>

void transpose_matrix(int matrix[10][10],int r,int c,int result[10][10])
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            result[j][i] = matrix[i][j];
        }
    }

    for (i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int r,c,matrix[10][10],i,j,result[10][10];
    FILE *fp;

    fp = fopen("matrix.txt","r");

    if(fp == NULL)
    {
        printf("file does not exist.");
        exit(0);
    }

    fscanf(fp,"%d %d",&r,&c);

    for(i=0 ; i<r ;i++)
    {
        for(j=0;j<c;j++)
        {
            fscanf(fp,"%d",&matrix[i][j]);
        }
    }


    transpose_matrix(matrix,r,c,result);

    fclose(fp);
    return 0;
}