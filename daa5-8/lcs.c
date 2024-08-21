#include <stdio.h>
#include <string.h>

// Function to find the length of the longest common subsequence
int lcs(char *X, char *Y, int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;

    // Building the LCS table in bottom-up manner
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else
            {
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
            }
        }
    }

    // L[m][n] contains the length of the LCS for X[0..m-1], Y[0..n-1]
    return L[m][n];
}

// Function to print the LCS
void printLCS(char *X, char *Y, int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;

    // Building the LCS table in bottom-up manner
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else
            {
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
            }
        }
    }

    // Following the table to print the LCS
    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0'; // Set the terminating character

    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s\n", lcs);
}

int main()
{
    char X[100], Y[100];

    // Input strings from the user
    printf("Enter the first string: ");
    scanf("%s", X);
    printf("Enter the second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    // Call the LCS function
    int length = lcs(X, Y, m, n);
    printf("Length of the Longest Common Subsequence: %d\n", length);

    // Print the LCS
    printLCS(X, Y, m, n);

    printf("Name: Kailash Badu \n");
    printf("Roll number: 09\n");

    return 0;
}
