#include <stdio.h>

void merge(int a[100], int l, int m, int u) {
    int i, j, k, b[100];
    i = 0, j = 0, k = 0;

    while (i <= m && j <= u) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    if (i > m) {
        while (j <= u) {
            b[k] = a[j];
            j++;
            k++;
        }
    } else {
        while (i <= m) {
            b[k] = a[i];
            i++;
            k++;
        }
    }

    for (k = l; k <= u-1; k++) {
        a[k] = b[k];
    }
}

void mergesort(int a[100], int l, int u) {
    if (l >= u) {
        return;
    }

    int m = (l + u) / 2;

    mergesort(a, l, m);
    mergesort(a, m + 1, u);
    merge(a, l, m, u);
}

int main() {
    int i, n, a[100];

    printf("Enter number of elements in an array\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Input array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    mergesort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
} 