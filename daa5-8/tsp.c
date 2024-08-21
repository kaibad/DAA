#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 25
#define INF INT_MAX

int matrix[MAX_CITIES][MAX_CITIES], visited_cities[MAX_CITIES], limit, cost = 0;

// Function to find the nearest unvisited city from current city
int tsp(int c)
{
    int count, nearest_city = -1;
    int minimum = INF;

    for (count = 0; count < limit; count++)
    {
        if ((matrix[c][count] != 0) && (visited_cities[count] == 0))
        {
            if (matrix[c][count] < minimum)
            {
                minimum = matrix[c][count];
                nearest_city = count;
            }
        }
    }

    if (nearest_city != -1)
    {
        cost += matrix[c][nearest_city];
    }

    return nearest_city;
}

// Recursive function to calculate the minimum cost path
void minimum_cost(int city)
{
    int nearest_city;
    visited_cities[city] = 1;
    printf("%d ", city + 1);
    nearest_city = tsp(city);

    if (nearest_city == -1)
    {
        // Return to the starting city
        nearest_city = 0;
        printf("%d ", nearest_city + 1);
        cost += matrix[city][nearest_city];
        return;
    }

    minimum_cost(nearest_city);
}

int main()
{
    int i, j;

    printf("Enter Total Number of Cities (up to %d):\t", MAX_CITIES);
    scanf("%d", &limit);

    if (limit > MAX_CITIES)
    {
        printf("Limit exceeds maximum number of cities (%d).\n", MAX_CITIES);
        return 1;
    }

    printf("\nEnter Cost Matrix (%d x %d):\n", limit, limit);
    for (i = 0; i < limit; i++)
    {
        printf("Enter %d elements for Row %d:\n", limit, i + 1);
        for (j = 0; j < limit; j++)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] < 0)
            {
                printf("Cost cannot be negative.\n");
                return 1;
            }
        }
        visited_cities[i] = 0;
    }

    printf("\nEntered Cost Matrix:\n");
    for (i = 0; i < limit; i++)
    {
        for (j = 0; j < limit; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nPath:\t");
    minimum_cost(0); // Start from the first city
    printf("\n\nMinimum Cost: \t%d\n", cost);
    printf("Name: Kailash Badu \n");
    printf("Roll number: 09\n");

    return 0;
}
