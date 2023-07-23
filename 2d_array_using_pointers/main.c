#include <stdio.h>
#include<stdlib.h>

int main()
{
    int a[3][3] = { {1,2,3,},
                   {4,5,6},
                   {7,8,9}};
    int *b[3];
    b[0] = (int*) malloc(3*sizeof(int));
    b[1] = (int*) malloc(3*sizeof(int));
    b[2] = (int*) malloc(3*sizeof(int));

    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d",b[i][j]);
        }
        printf("\n");
    }

    int **c;

    c = (int**) malloc(3*sizeof(int*));

    c[0] = (int*) malloc(3*sizeof(int));
    c[1] = (int*) malloc(3*sizeof(int));
    c[2] = (int*) malloc(3*sizeof(int));

    printf("\n");

    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d",c[i][j]);
        }
        printf("\n");

    }
    return 0;
}
