#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Function to print the subset
void printSubset(int subset[], int subsetSize)
{
    printf("{ ");
    for (int i = 0; i < subsetSize; i++)
    {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

// Recursive function to find if there is a subset with the given sum
bool subsetSum(int arr[], int n, int targetSum, int subset[], int subsetSize)
{
    // Base case: if targetSum is 0, then we found a subset
    if (targetSum == 0)
    {
        printSubset(subset, subsetSize);
        return true;
    }

    // Base case: no elements left or targetSum is negative
    if (n == 0 || targetSum < 0)
    {
        return false;
    }

    // Exclude the last element
    if (subsetSum(arr, n - 1, targetSum, subset, subsetSize))
    {
        return true;
    }

    // Include the last element
    subset[subsetSize] = arr[n - 1];
    if (subsetSum(arr, n - 1, targetSum - arr[n - 1], subset, subsetSize + 1))
    {
        return true;
    }

    return false;
}

int main()
{
    int n, targetSum;
    int arr[MAX], subset[MAX];

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input the elements of the array
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Input the target sum
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    // Initialize the subset array
    for (int i = 0; i < MAX; i++)
    {
        subset[i] = 0;
    }

    // Call the subset sum function
    if (!subsetSum(arr, n, targetSum, subset, 0))
    {
        printf("No subset with the given sum exists.\n");
    }

    printf("Name: Kailash Badu \n");
    printf("Roll number: 09\n");

    return 0;
}
