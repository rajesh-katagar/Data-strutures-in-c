#include<stdio.h>
#include<stdlib.h>

// Structure to store job information
struct Job {
    int id;
    int deadline;
    int profit;
};

// Function to compare jobs based on their profits
int compare(const void* a, const void* b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

// Function to find the maximum profit using branch and bound
int findMaxProfit(int n, struct Job jobs[]) {
    int i, j, k;
    int maxProfit = 0;
    int maxDeadline = 0;

    // Sort the jobs based on their profits
    qsort(jobs, n, sizeof(struct Job), compare);

    // Find the maximum deadline
    for (i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Create an array to store the scheduled jobs
    int* slot = (int*)malloc(maxDeadline * sizeof(int));
    for (i = 0; i < maxDeadline; i++) {
        slot[i] = -1;
    }

    // Traverse through the sorted jobs and schedule them
    for (i = 0; i < n; i++) {
        // Find a free slot before the deadline for the job
        for (j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                maxProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Free the allocated memory
    free(slot);

    return maxProfit;
}

int main() {
    int n, i;
    struct Job* jobs;

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    // Allocate memory for the job array
    jobs = (struct Job*)malloc(n * sizeof(struct Job));

    // Read the job details from the user
    for (i = 0; i < n; i++) {
        printf("Enter the deadline and profit of job %d: ", i + 1);
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
        jobs[i].id = i + 1;
    }

    // Find the maximum profit using branch and bound
    int maxProfit = findMaxProfit(n, jobs);

    printf("The maximum profit is %d\n", maxProfit);

    // Free the allocated memory
    free(jobs);

    return 0;
}
