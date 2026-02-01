#include <stdio.h>
#include <string.h>

#define MAX 100

char queue[MAX];
int front = 0, rear = -1;

void enqueue(char ch) {
    queue[++rear] = ch;
}

char dequeue() {
    return queue[front++];
}

int main() {
    char str[MAX];
    int i, len, isPalindrome = 1;

    printf("Enter string: ");
    scanf("%s", str);

    len = strlen(str);

    // Insert into queue
    for (i = 0; i < len; i++) {
        enqueue(str[i]);
    }

    // Compare with original (array)
    for (i = len - 1; i >= 0; i--) {
        if (str[i] != dequeue()) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}