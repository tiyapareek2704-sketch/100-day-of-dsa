#include <stdio.h>

#define MAX 100

int queue[MAX], front = 0, rear = -1;
int stack[MAX], top = -1;

// Enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Push to stack
void push(int x) {
    stack[++top] = x;
}

// Pop from stack
int pop() {
    return stack[top--];
}

// Check if queue is empty
int isQueueEmpty() {
    return front > rear;
}

// Check if stack is empty
int isStackEmpty() {
    return top == -1;
}

int main() {
    int n, i, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Move queue to stack
    while (!isQueueEmpty()) {
        push(dequeue());
    }

    // Step 2: Move stack back to queue
    front = 0;
    rear = -1;

    while (!isStackEmpty()) {
        enqueue(pop());
    }

    // Display reversed queue
    printf("Reversed queue: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}