#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

// DFS function
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int edges, u, v, start;

    // Input number of vertices
    scanf("%d", &n);

    // Initialize matrix
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input number of edges
    scanf("%d", &edges);

    // Input edges
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // remove for directed graph
    }

    // Input starting vertex
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}