#include <stdbool.h>

#define MAX 2000

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];

bool dfs(int node, int n) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1) {
            if (visited[i] == 0) {
                if (dfs(i, n))
                    return true;
            } else if (recStack[i] == 1) {
                return true;
            }
        }
    }

    recStack[node] = 0;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    
    for (int i = 0; i < numCourses; i++) {
        visited[i] = 0;
        recStack[i] = 0;
        for (int j = 0; j < numCourses; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        graph[b][a] = 1;
    }

    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            if (dfs(i, numCourses))
                return false;
        }
    }

    return true;
}
