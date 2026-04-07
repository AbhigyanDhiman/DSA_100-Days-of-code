#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int n;

int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1) {
            if (visited[i] == 0) {
                if (dfs(i) == 1)
                    return 1;
            } else if (recStack[i] == 1) {
                return 1;
            }
        }
    }

    recStack[node] = 0;
    return 0;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (dfs(i) == 1) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}
