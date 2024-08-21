#include<stdio.h>
#define MAX 100
// Function to find the minimum and maximum values in an aay
void findMinMax(int a[], int n, int *min, int *max)
{
    // Initialize min and max to the first element of the aay
    *min = a[0];
    *max = a[0];
    // Iterate through the aay starting from the second element
    for (int i = 1; i < n; i++)
    {
        if (a[i] < *min)
        {
            *min = a[i];
        }
        if (a[i] > *max)
        {
            *max = a[i];
        }
    }
}
int main()
{
    int i, n, min, max, a[MAX];
    printf("Enter then size of list: ");
    scanf("%d", &n);
    printf("\nEnter the content of list : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    findMinMax(a, n, &min, &max);
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
    printf("\nName:Kailash Badu\n");
    printf("Roll number:09");
    return 0;
}
