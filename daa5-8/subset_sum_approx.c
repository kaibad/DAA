#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEMENTS 30

// Function to find the closest subset sum to the target
int closestSubsetSum(int arr[], int n, int target)
{
    int total = 1 << n; // Total number of subsets
    int closest = 0;    // Closest sum to the target

    // Generate all possible subsets and calculate their sums
    for (int i = 0; i < total; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum += arr[j];
            }
        }
        if (abs(target - sum) < abs(target - closest))
        {
            closest = sum;
        }
    }
    return closest;
}

int main()
{
    int n, target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Ensure the number of elements does not exceed the maximum allowed
    if (n > MAX_ELEMENTS)
    {
        printf("The number of elements cannot exceed %d.\n", MAX_ELEMENTS);
        return 1;
    }

    int arr[MAX_ELEMENTS];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    // Call the approximation function
    int closest = closestSubsetSum(arr, n, target);
    printf("The closest subset sum to the target is: %d\n", closest);

    printf("Name: Kailash Badu \n");
    printf("Roll number: 09\n");

    return 0;
}
