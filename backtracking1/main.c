#include <stdio.h>

// Function to print the contents of a given array
void printCombination(int out[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", out[i]);
    }

    printf("\n");
}

// Recursive function to print all combinations of numbers from `i` to `n`
// having sum `n`. The `index` denotes the next free slot in the output array `out`
void printCombinations(int i, int n, int out[], int index)
{
    // if the sum becomes `n`, print the combination
    if (n == 0) {
        printCombination(out, index);
    }

    // start from the previous element in the combination till `n`
    for (int j = i; j <= n; j++)
    {
        // place current element at the current index
        out[index] = j;

        // recur with a reduced sum
        printCombinations(j, n - j, out, index + 1);
    }
}

int main(void)
{
    int n;

    printf("Enter n\n");
    scanf("%d",&n);

    int out[n];

    // print all combinations of numbers from 1 to `n` having sum `n`
    printCombinations(1, n, out, 0);

    return 0;
}
