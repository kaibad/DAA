#include <stdio.h>
int gcd(int a, int b)
{
    int r;
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    else
    {
        while (b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
}
int main()
{
    int a, b;
    printf("Enter the two numbers: ");
    scanf("%d %d", &a, &b);

    printf("GCD (%d,%d) : %d\n", a, b, gcd(a, b));
    printf("Name:Kailash Badu\n");
    printf("Roll No.:09");
    return 0;
}
