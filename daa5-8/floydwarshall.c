#include <stdio.h>
#include <limits.h>

// Number of vertices in the graph
#define V 4

// Function to print the solution matrix
void printSolution(int dist[][V])
{
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INT_MAX)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Function to implement Floyd-Warshall algorithm
void floydWarshall(int graph[][V])
{
    int dist[V][V]; // dist[i][j] will hold the shortest distance from i to j

    // Initialize the solution matrix same as input graph matrix.
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Add all vertices one by one to the set of intermediate vertices.
    for (int k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

int main()
{
    int graph[V][V] = {{0, 5, INT_MAX, 10},
                       {INT_MAX, 0, 3, INT_MAX},
                       {INT_MAX, INT_MAX, 0, 1},
                       {INT_MAX, INT_MAX, INT_MAX, 0}};

    // Run Floyd-Warshall algorithm
    floydWarshall(graph);

    printf("Name: Kailash Badu \n");
    printf("Roll number: 09\n");

    return 0;
}
