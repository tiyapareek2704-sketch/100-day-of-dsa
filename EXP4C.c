#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Insert
void insert(int val) {
    if ((rear + 1) % MAX == front) {
        printf("Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = val;
}

// Delete
void delete() {
    if (front == -1) {
        printf("Underflow\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

// Display
void display() {
    if (front == -1) {
        printf("Empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    display();

    delete();
    display();
}