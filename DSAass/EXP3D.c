#include <stdio.h>
#include <stdlib.h>

struct Poly {
    int coef, exp;
    struct Poly* next;
};

int main()
{
    printf("Program is running successfully\n");
    return 0;
}