//TO CHECK THE SYMMETRY OF MATRIX

#include<stdio.h>

void read(int a[10][10],int r,int c,FILE *fp)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            fscanf(fp,"%d",&a[i][j]);
        }
    }
}

int transpose(int a[10][10],int r,int c)
{
    int trans[10][10];
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            trans[i][j]=a[j][i];
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(trans[i][j]!=a[i][j])
                return 0;
        }
    }
    return 1;
}

int main() {
    int num[10][10];
    int r, c, status = 1;
    FILE *fp;
    fp = fopen("symmetry.txt", "r");
    fscanf(fp,"%d %d", &r, &c);
    if (r == c)
    {
        read(num, r, c, fp);
        status = transpose(num, r, c);
        if (status == 1)
        {
            printf("Matrix is Symmetric\n");
        }
        else
            printf("Matrix is not Symmetric\n");
    }
    else
        printf("The given matrix is not square matrix\n");
    fclose(fp);
    return 0;
}