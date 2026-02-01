#include <stdio.h>
#define MAX 100

int q1[MAX], q2[MAX];
int f1 = 0, r1 = -1;
int f2 = 0, r2 = -1;

// Enqueue in q1
void enqueue1(int x) {
    q1[++r1] = x;
}

// Enqueue in q2
void enqueue2(int x) {
    q2[++r2] = x;
}

// Dequeue from q1
int dequeue1() {
    return q1[f1++];
}

// Push
void push(int x) {
    enqueue2(x);

    while (f1 <= r1)
        enqueue2(dequeue1());

    // Swap q1 and q2
    for (int i = f2; i <= r2; i++)
        q1[i - f2] = q2[i];

    r1 = r2 - f2;
    f1 = 0;

    f2 = 0;
    r2 = -1;
}

// Pop
void pop() {
    if (f1 > r1) {
        printf("Stack Empty\n");
        return;
    }
    printf("Popped: %d\n", dequeue1());
}

// Display
void display() {
    for (int i = f1; i <= r1; i++)
        printf("%d ", q1[i]);
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();
}