#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int p;
    int w;
    float pw;
} item;

item items[MAX];
int n;
int W;
int maxprofit = 0;
int x[MAX];
int bestx[MAX];

void knapsack(int i, int profit, int weight) {
    if (i > n) {
        if (profit > maxprofit) {
            maxprofit = profit;
            for (int j = 1; j <= n; j++) {
                bestx[j] = x[j];
            }
        }
        return;
    }
    if (weight + items[i].w <= W) {
        x[i] = 1;
        knapsack(i+1, profit+items[i].p, weight+items[i].w);
    }
    if (profit + (items[i].pw * (W - weight)) > maxprofit) {
        x[i] = 0;
        knapsack(i+1, profit, weight);
    }
}

int main() {
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Enter the profit and weight of each item:\n");
    for (int i = 1; i <= n; i++) {
        printf("Item %d: ", i);
        scanf("%d %d", &items[i].p, &items[i].w);
        items[i].pw = (float)items[i].p / (float)items[i].w;
    }

    knapsack(1, 0, 0);

    printf("Maximum profit: %d\n", maxprofit);
    printf("Items in the knapsack: ");
    for (int i = 1; i <= n; i++) {
        if (bestx[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
