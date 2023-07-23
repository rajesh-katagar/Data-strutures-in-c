#include <stdio.h>

// Structure to represent a subarray
struct Subarray {
    int left, right, sum;
};

// Function to find maximum subarray sum using brute force approach
struct Subarray findMaxSubarray(int arr[], int n) {
    struct Subarray sub = {0, 0, arr[0]}; // initialize with first element as default max subarray

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum > sub.sum) {
                sub.sum = sum;
                sub.left = i;
                sub.right = j;
            }
        }
    }

    return sub;
}

// Main function to test the brute force approach
int main()
{

    int i,n,arr[20];

    printf("Enter n value\n");
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }


    struct Subarray sub = findMaxSubarray(arr, n);

    printf("Maximum sum of subarray: %d\n", sub.sum);
    printf("Subarray range: [%d, %d]\n", sub.left, sub.right);

    return 0;
}
