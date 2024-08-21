#include <stdio.h>

// Function to compute the GCD of two numbers using Euclid's Algorithm
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to solve the modular linear equation ax ≡ b (mod m)
void solveModularLinearEquation(int a, int b, int m)
{
    int d = gcd(a, m);

    // Check if b is divisible by the gcd of a and m
    if (b % d != 0)
    {
        printf("No solution exists\n");
        return;
    }

    // Scale a, b, and m by d to find a particular solution
    int a_prime = a / d;
    int b_prime = b / d;
    int m_prime = m / d;

    // Find the multiplicative inverse of a_prime modulo m_prime
    // Using the property that a_prime and m_prime are coprime (gcd(a_prime, m_prime) == 1)
    int x = 0;
    int found = 0;

    for (int i = 0; i < m_prime; i++)
    {
        if ((a_prime * i) % m_prime == 1)
        {
            x = i;
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("No multiplicative inverse exists\n");
        return;
    }

    // Compute the particular solution
    int x0 = (x * b_prime) % m_prime;

    // Ensure the solution is positive
    if (x0 < 0)
    {
        x0 += m_prime;
    }

    // Print the solution
    printf("A solution is x = %d\n", x0);
    printf("General solution: x = %d + k * %d\n", x0, m_prime);
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
