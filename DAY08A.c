#include <stdio.h>

// Recursive function to calculate a^b
long long power(int a, int b)
{
    if (b == 0)
        return 1;          // Base case: a^0 = 1
    else
        return a * power(a, b - 1);   // Recursive case
}

int main()
{
    int a, b;

    // Taking input
    scanf("%d %d", &a, &b);

    // Printing result
    printf("%lld", power(a, b));

    return 0;
}