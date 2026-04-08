int* result;
int idx;

int dfs(int node, int** adj, int* colSize, int* state) {
    if (state[node] == 1) return 0;
    if (state[node] == 2) return 1;

    state[node] = 1;

    for (int i = 0; i < colSize[node]; i++) {
        if (!dfs(adj[node][i], adj, colSize, state))
            return 0;
    }

    state[node] = 2;
    result[idx--] = node;
    return 1;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int* colSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < prerequisitesSize; i++)
        colSize[prerequisites[i][1]]++;

    int** adj = (int**)malloc(numCourses * sizeof(int*));
    for (int i = 0; i < numCourses; i++)
        adj[i] = (int*)malloc(colSize[i] * sizeof(int));

    int* temp = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < prerequisitesSize; i++) {
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];
        adj[u][temp[u]++] = v;
    }

    int* state = (int*)calloc(numCourses, sizeof(int));
    result = (int*)malloc(numCourses * sizeof(int));
    idx = numCourses - 1;

    for (int i = 0; i < numCourses; i++) {
        if (state[i] == 0) {
            if (!dfs(i, adj, colSize, state)) {
                *returnSize = 0;
                return result;
            }
        }
    }

    *returnSize = numCourses;
    return result;
}
