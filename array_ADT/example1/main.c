#include <stdio.h>
#include <stdlib.h>

struct array
{
  //  int *a;
    int a[20];
    int size,length;
};

void display(struct array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ",arr.a[i]);
    }
}

int main()
{
    struct array arr = {{1,2,3,4,5,6},5,6};;
        display(arr);

    return 0;
}
