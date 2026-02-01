#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

// DFS function to detect cycle
int dfs(int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {  // if edge exists
            if (visited[i] == 0) {
                if (dfs(i, node)) {
                    return 1; // cycle found
                }
            }
            else if (i != parent) {
                return 1; // visited and not parent → cycle
            }
        }
    }
    return 0;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // initialize visited
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int hasCycle = 0;

    // handle disconnected graph
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (dfs(i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}