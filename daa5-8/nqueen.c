#include <stdio.h>
#include <stdbool.h>

#define MAX_N 15 // Define the maximum size of the board

// Function to print the chessboard with queens placed
void printSolution(int board[MAX_N][MAX_N], int N)
{
    printf("Solution:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1)
            {
                printf(" Q ");
            }
            else
            {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int board[MAX_N][MAX_N], int row, int col, int N)
{
    // Check this row on the left side
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(int board[MAX_N][MAX_N], int col, int N)
{
    // Base case: If all queens are placed
    if (col >= N)
    {
        return true;
    }

    // Try placing this queen in all rows in the current column
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col, N))
        {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueens(board, col + 1, N))
            {
                return true;
            }

            // If placing queen in board[i][col] doesn't lead to a solution, remove queen
            board[i][col] = 0;
        }
    }

    return false;
}

int main()
{
    int N;
    int board[MAX_N][MAX_N] = {0}; // Initialize the board with 0s

    // Input the size of the board (N)
    printf("Enter the number of queens (N): ");
    scanf("%d", &N);

    // Check if the size is within the acceptable range
    if (N > MAX_N)
    {
        printf("The maximum number of queens allowed is %d.\n", MAX_N);
        return 1;
    }

    // Solve the N-Queens problem
    if (solveNQueens(board, 0, N))
    {
        printSolution(board, N);
    }
    else
    {
        printf("No solution exists for N = %d.\n", N);
    }

    printf("Name: Kailash Badu \n");
    printf("Roll number: 09\n");

    return 0;
}
