#include <stdio.h>

int minCoins(int amount,int coinsavailable[],int numberofCoins) {
    int count = 0;
    int i = numberofCoins - 1; // start with the largest coin

    while (amount > 0)
    {
        if (coinsavailable[i] <= amount)
        {
            amount = amount - coinsavailable[i];
            count++; //coin count
        }
        else
        {
            i--; // try smaller coin
        }
    }

    return count;
}

int main() {
    int amount;

    int coinsavailable[] = {1, 2, 5,10, 20}; // available coins
    int numberofCoins = 5; // number of types of available coins

    printf("Enter the amount: ");
    scanf("%d", &amount);

    int num = minCoins(amount,coinsavailable,numberofCoins);
    printf("Minimum number of coins required: %d\n", num);

    return 0;
}
