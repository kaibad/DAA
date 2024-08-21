#include <stdio.h>

#define MAX_ITEMS 100

// Function to calculate the maximum value using backtracking
void knapsack(int weights[], int values[], int n, int capacity, int currentIndex, int currentWeight, int currentValue, int *maxValue)
{
    // Base case: If current weight exceeds capacity, return
    if (currentWeight > capacity)
    {
        return;
    }

    // Update the maximum value if the current value is higher
    if (currentValue > *maxValue)
    {
        *maxValue = currentValue;
    }

    // Try including the next item
    for (int i = currentIndex; i < n; i++)
    {
        knapsack(weights, values, n, capacity, i + 1, currentWeight + weights[i], currentValue + values[i], maxValue);
    }
}

int main()
{
    int n, capacity;
    int weights[MAX_ITEMS], values[MAX_ITEMS];

    // Input the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Input the weights and values of the items
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weights[i]);
    }

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &values[i]);
    }

    // Input the capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int maxValue = 0;

    // Call the knapsack function
    knapsack(weights, values, n, capacity, 0, 0, 0, &maxValue);

    printf("The maximum value that can be obtained is: %d\n", maxValue);

    printf("Name: Kailash Badu \n");
    printf("Roll number: 09\n");

    return 0;
}
