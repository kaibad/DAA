#include <stdio.h>
#define MAX 100
int linearSearch(int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int i, n, key, location, a[MAX];
    printf("Enter the size of list: ");
    scanf("%d", &n);
    printf("\nEnter the content of list : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nEnter the element to find in array: ");
    scanf("%d", &key);
    location = linearSearch(a, n, key);

    if (location == -1)
    {
        printf("\n%d is not in the list", key);
    }
    else
    {
        printf("%d is in the index %d of the array\n", key, location);
    }

    printf("Name:Kailash Badu\n");
    printf("Roll number:09");

    return 0;
}
