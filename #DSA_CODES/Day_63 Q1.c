#include <stdio.h>

int visited[100];

void dfs(int v, int n, int adj[n][n]) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i, n, adj);
        }
    }
}

int main() {
    int n, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    dfs(start, n, adj);

    return 0;
}
