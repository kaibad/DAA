#include <stdio.h>

// Function to return the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];

    // Build table dp[][] in a bottom-up manner
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0; // Base case: no items or zero capacity
            }
            else if (wt[i - 1] <= w)
            {
                // Include the item or exclude it
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w]; // Exclude the item
            }
        }
    }

    // The maximum value that can be carried in the knapsack of capacity W
    return dp[n][W];
}

int main()
{
    int n, W;

    // Input number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];

    // Input values and weights of items
    printf("Enter the values of the items: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val[i]);
    }

    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &wt[i]);
    }

    // Input the capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    // Calculate the maximum value that can be carried
    int maxValue = knapsack(W, wt, val, n);

    // Output the result
    printf("The maximum value that can be carried in the knapsack is: %d\n", maxValue);

    printf("Name: Kailash Badu \n");
    printf("Roll number: 09\n");

    return 0;
}
