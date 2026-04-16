bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int color[graphSize];
    for (int i = 0; i < graphSize; i++) color[i] = 0; // 0: uncolored, 1: Red, -1: Blue

    for (int i = 0; i < graphSize; i++) {
        if (color[i] != 0) continue;

        // Standard BFS Queue
        int queue[graphSize];
        int head = 0, tail = 0;
        
        queue[tail++] = i;
        color[i] = 1; // Start coloring first node in component Red

        while (head < tail) {
            int curr = queue[head++];
            
            for (int j = 0; j < graphColSize[curr]; j++) {
                int neighbor = graph[curr][j];
                
                if (color[neighbor] == 0) {
                    // Color neighbor with the opposite color
                    color[neighbor] = -color[curr];
                    queue[tail++] = neighbor;
                } else if (color[neighbor] == color[curr]) {
                    // Found two adjacent nodes with the same color
                    return false;
                }
            }
        }
    }
    return true;
}
