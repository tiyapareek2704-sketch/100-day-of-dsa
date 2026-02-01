#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// check empty
int isEmpty() {
    return front == -1;
}

// check full
int isFull() {
    return (front == 0 && rear == MAX-1) || (front == rear + 1);
}

// push front
void push_front(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    deque[front] = x;
}

// push back
void push_back(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = x;
}

// pop front
void pop_front() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % MAX;
    }
}

// pop back
void pop_back() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

// display
void display() {
    if (isEmpty()) return;

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    // Example usage
    push_back(10);
    push_back(20);
    push_front(5);
    pop_back();

    display(); // Output: 5 10

    return 0;
}