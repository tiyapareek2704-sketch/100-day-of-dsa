#include <stdio.h>
#include <string.h>

// Recursive function to reverse string
void reverse(char str[], int start, int end)
{
    if (start >= end)
        return;

    // Swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call
    reverse(str, start + 1, end - 1);
}

int main()
{
    char str[100];

    // Taking input
    scanf("%s", str);

    int length = strlen(str);

    // Calling recursive function
    reverse(str, 0, length - 1);

    // Printing result
    printf("%s", str);

    return 0;
}