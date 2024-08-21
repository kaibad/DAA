#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of multiplications
int matrixChainOrder(int p[], int n)
{
    int m[n][n]; // m[i][j] will store the minimum number of scalar multiplications needed to compute the matrix A[i]A[i+1]...A[j]

    // No cost is needed to multiply one matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // l is the chain length
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1]; // The minimum cost to multiply matrices from A1 to An
}

int main()
{
    int n;

    // Input the number of matrices
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];
    printf("Enter the dimensions: ");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    int minCost = matrixChainOrder(p, n + 1);

    printf("Minimum number of multiplications is: %d\n", minCost);

    printf("Name: Kailash Badu \n");
    printf("Roll number: 09\n");

    return 0;
}
