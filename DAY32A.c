#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    top++;
    stack[top] = value;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        top--;
    }
}

void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m;

    // number of elements
    scanf("%d", &n);

    // pushing elements
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        push(value);
    }

    // number of pops
    scanf("%d", &m);

    // popping elements
    for (int i = 0; i < m; i++) {
        pop();
    }

    // display remaining stack
    display();

    return 0;
}