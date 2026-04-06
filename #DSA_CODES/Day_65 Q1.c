#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

int dfs(int node, int parent, int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node, n))
                    return 1;
            }
            else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int hasCycle(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    if (hasCycle(n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
