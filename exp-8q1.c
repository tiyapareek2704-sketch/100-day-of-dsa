#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];

int main() {
int n, m, u, v, i, j, vertex;
int indegree, outdegree;


printf("Enter number of vertices: ");
scanf("%d", &n);

printf("Enter number of edges: ");
scanf("%d", &m);

// Initialize matrix with 0
for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
        adj[i][j] = 0;
    }
}

// Input edges
printf("Enter edges (u v):\n");
for(i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    adj[u][v] = 1;   // Directed graph
}

// Display adjacency matrix
printf("\nAdjacency Matrix:\n");
for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
        printf("%d ", adj[i][j]);
    }
    printf("\n");
}

// Find degree of a vertex
printf("\nEnter vertex to find degree: ");
scanf("%d", &vertex);

indegree = 0;
outdegree = 0;

for(i = 0; i < n; i++) {
    outdegree += adj[vertex][i]; // row sum
    indegree += adj[i][vertex];  // column sum
}

printf("In-degree of %d = %d\n", vertex, indegree);
printf("Out-degree of %d = %d\n", vertex, outdegree);

return 0;


}
