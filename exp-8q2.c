#include <stdio.h>

#define MAX 10

int main() {
int n, adj[MAX][MAX];
int i, j;
int isUndirected = 1;


printf("Enter number of vertices: ");
scanf("%d", &n);

printf("Enter adjacency matrix:\n");
for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
        scanf("%d", &adj[i][j]);
    }
}

// Check symmetry
for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
        if(adj[i][j] != adj[j][i]) {
            isUndirected = 0;
            break;
        }
    }
    if(isUndirected == 0)
        break;
}

if(isUndirected)
    printf("Graph is Undirected (Matrix is Symmetric)\n");
else
    printf("Graph is Directed (Matrix is Not Symmetric)\n");

return 0;


}
