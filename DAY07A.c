#include <stdio.h>

// Recursive function
int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;

    // Taking input
    scanf("%d", &n);

    // Printing result
    printf("%d", fib(n));

    return 0;
}