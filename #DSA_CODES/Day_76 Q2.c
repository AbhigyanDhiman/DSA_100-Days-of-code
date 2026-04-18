#include <stdio.h>
#include <stdlib.h>

int timer;

int min(int a, int b) {
    return (a < b) ? a : b;
}

void dfs(int u, int p, int* disc, int* low, int** adj, int* adjSize, int** result, int* returnSize) {
    disc[u] = low[u] = ++timer;
    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];
        if (v == p) continue;
        if (disc[v] == 0) {
            dfs(v, u, disc, low, adj, adjSize, result, returnSize);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                result[*returnSize][0] = u;
                result[*returnSize][1] = v;
                (*returnSize)++;
            }
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize, int* connectionsColSize, int* returnSize, int** returnColumnSizes) {
    int* adjSize = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < connectionsSize; i++) {
        adjSize[connections[i][0]]++;
        adjSize[connections[i][1]]++;
    }

    int** adj = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }

    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    int* disc = (int*)calloc(n, sizeof(int));
    int* low = (int*)calloc(n, sizeof(int));
    int** result = (int**)malloc(connectionsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(connectionsSize * sizeof(int));
    for (int i = 0; i < connectionsSize; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
        (*returnColumnSizes)[i] = 2;
    }

    timer = 0;
    *returnSize = 0;

    dfs(0, -1, disc, low, adj, adjSize, result, returnSize);

    free(disc);
    free(low);
    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);
    free(adjSize);

    return result;
}
