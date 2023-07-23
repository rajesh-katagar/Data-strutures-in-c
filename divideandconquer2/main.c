/*
NAME:RAJESH KATAGAR
DIV - E  ROLL NUMBER - 514
PROGRAM - BINARY SEARCH
        TIME COMPLEXITY - O(logn)
*/
#include <stdio.h>
#include <stdlib.h>                                             // 3 7 9 2 11

int binarysearch(int l, int h, int key, int a[])
{
    if (l > h)
    {
       exit(0);
    }
    else
    {
        int m = (l + h) / 2;//MIDDLE ELEMENT
        if (key == a[m])
            return m;
        else if (key < a[m])//IF KEY ELEMENT IS WITHIN MIDDLE RANGE
            return binarysearch(l, m - 1, key, a);
        else
            return binarysearch(m + 1, h, key, a);
    }
}

int main() {
    int i, key, n, a[20], s, l, h,temp,j;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    l = 0;
    h = n - 1;

    //SORT THE ARRAY FIRST
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    //CALL THE FUNCTION
    s = binarysearch(l, h, key, a);

    if (s == -1) {
        printf("%d is not present in the array.", key);
    } else {
        printf("%d is present at index %d in the array.", key, s);
    }

    return 0;
}
