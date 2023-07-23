#include <stdio.h>

int fib(int n) {
    int memory[n+1];
    memory[0] = 0;
    memory[1] = 1;
    for (int i = 2; i <= n; i++) {
        memory[i] = memory[i-2] + memory[i-1];
    }
    return memory[n];
}

int main()
{
    int n;
    printf("Enter n value\n");
    scanf("%d",&n);


    for(int i=0;i<n;i++)
    {
        printf("Fibonacci(%d) = %d\n", i,fib(i));
    }
    return 0;
}
