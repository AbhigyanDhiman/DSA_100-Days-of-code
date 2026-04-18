#include <stdio.h>

int adj[100][100];
int visited[100];
int n, m;

void dfs(int node) {
    visited[node] = 1;
    
    for(int i = 1; i <= n; i++) {
        if(adj[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int u, v;
    
    scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }
    
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    dfs(1);
    
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            printf("NOT CONNECTED");
            return 0;
        }
    }
    
    printf("CONNECTED");
    
    return 0;
}
