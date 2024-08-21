#include <stdio.h>
#define MAX 100

void findMinMax(int a[], int l, int r, int *min, int *max)
{
    int min1, max1, min2, max2;
    if (l == r) // Base case: only one element
    {
        *min = a[l];
        *max = a[l];
    }
    else if (r == l + 1) // Base case: two elements
    {
        if (a[l] < a[r])
        {
            *min = a[l];
            *max = a[r];
        }
        else
        {
            *min = a[r];
            *max = a[l];
        }
    }
    else // Recursive case
    {
        int mid = (l + r) / 2;
        findMinMax(a, l, mid, &min1, &max1);
        findMinMax(a, mid + 1, r, &min2, &max2);
        *min = (min1 < min2) ? min1 : min2;
        *max = (max1 > max2) ? max1 : max2;
    }
}

int main()
{
    int i, n, min, max, a[MAX];
    printf("Enter the size of the list: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid size. Size should be between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Enter the content of the list: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    findMinMax(a, 0, n - 1, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
    printf("\nName: Kailash Badu\n");
    printf("Roll number: 09\n");

    return 0;
}
