#include <stdio.h>
int MatrixChainMultuplication(int a[20], int n) {
    int minMul[n][n];
    int j, q;
    for (int i = 1; i < n; i++)
        minMul[i][i] = 0;
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            minMul[i][j] = 99999999;
            for (int k = i; k <= j - 1; k++) {
                q = minMul[i][k] + minMul[k + 1][j] + a[i - 1] * a[k] * a[j];
                if (q < minMul[i][j])
                    minMul[i][j] = q;
            }
        }
    }
    return minMul[1][n - 1];
}
int main(){
    int a[20],n,s;
    printf("Enter n value\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    s = MatrixChainMultuplication(a,n);

    printf("Minimum number of multiplications required for the matrices multiplication is %d ",s);
    getchar();
    return 0;
}