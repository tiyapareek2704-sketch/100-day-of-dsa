#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

// Enqueue
void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

int main() {
    int n, i, j, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    // Initialize visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    // BFS
    enqueue(s);
    visited[s] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}