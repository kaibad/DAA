#include <stdio.h>

// Function to compute GCD and coefficients using Extended Euclidean Algorithm
int extendedGCD(int a, int b, int *x, int *y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedGCD(b, a % b, &x1, &y1);

    // Update x and y using results of recursion
    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

// Function to solve the modular linear equation ax ≡ b (mod m)
void solveModularLinearEquation(int a, int b, int m)
{
    int x, y;
    int d = extendedGCD(a, m, &x, &y);

    printf("Extended Euclidean Algorithm steps:\n");
    printf("GCD(%d, %d) = %d\n", a, m, d);
    printf("Coefficients: x = %d, y = %d\n", x, y);

    // Check if b is divisible by the GCD
    if (b % d != 0)
    {
        printf("No solution exists\n");
        return;
    }

    // Scale x and y to get a solution for the original equation
    int x0 = x * (b / d);
    int m0 = m / d;

    // Adjust the solution to be within the range of the modulus
    x0 = ((x0 % m0) + m0) % m0;

    // Print the solution
    printf("A particular solution is x = %d\n", x0);
    printf("General solution: x = %d + k * %d\n", x0, m0);
}

int main()
{
    int a, b, m;

    // Input coefficients and modulus
    printf("Enter coefficients a, b, and modulus m:\n");
    scanf("%d %d %d", &a, &b, &m);

    solveModularLinearEquation(a, b, m);

    printf("Name: Kailash Badu \n");
    printf("Roll number: 09\n");

    return 0;
}
