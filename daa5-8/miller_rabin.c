#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform modular exponentiation
unsigned long long modExp(unsigned long long base, unsigned long long exp, unsigned long long mod)
{
    unsigned long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to perform the Miller-Rabin primality test
int millerRabin(unsigned long long n, int k)
{
    if (n <= 1)
        return 0; // 0 and 1 are not prime
    if (n <= 3)
        return 1; // 2 and 3 are prime

    // Find r such that n-1 = 2^r * d
    unsigned long long d = n - 1;
    unsigned long long r = 0;
    while (d % 2 == 0)
    {
        d /= 2;
        r++;
    }

    // Perform k tests
    for (int i = 0; i < k; i++)
    {
        // Randomly pick a base
        unsigned long long a = 2 + rand() % (n - 4);

        // Compute a^d % n
        unsigned long long x = modExp(a, d, n);
        if (x == 1 || x == n - 1)
            continue;

        int continueOuterLoop = 0;
        for (unsigned long long j = 0; j < r - 1; j++)
        {
            x = modExp(x, 2, n);
            if (x == n - 1)
            {
                continueOuterLoop = 1;
                break;
            }
        }

        if (continueOuterLoop)
            continue;

        return 0; // Composite
    }

    return 1; // Probably prime
}

int main()
{
    unsigned long long n;
    int k;

    // Seed random number generator
    srand(time(NULL));

    // Input number and number of iterations
    printf("Enter the number to test for primality: ");
    scanf("%llu", &n);
    printf("Enter the number of iterations: ");
    scanf("%d", &k);

    if (millerRabin(n, k))
    {
        printf("%llu is probably prime.\n", n);
    }
    else
    {
        printf("%llu is composite.\n", n);
    }

    printf("Name: Kailash Badu \n");
    printf("Roll number: 09\n");

    return 0;
}
