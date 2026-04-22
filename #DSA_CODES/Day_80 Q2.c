#include <stdio.h>
#include <limits.h>

#define INF 1000001 // Slightly more than max possible threshold (10^4 * 100)

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    int dist[n][n];

    // Step 1: Initialize the distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    // Step 2: Load the direct edges (Bidirectional)
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Step 3: Floyd-Warshall Algorithm (All-Pairs Shortest Path)
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Step 4: Count reachable cities and find the result
    int minReachableCount = n;
    int resultCity = -1;

    for (int i = 0; i < n; i++) {
        int currentReachable = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) {
                currentReachable++;
            }
        }

        // Update result if we find a smaller count, 
        // or the same count but a larger city index (i >= resultCity)
        if (currentReachable <= minReachableCount) {
            minReachableCount = currentReachable;
            resultCity = i;
        }
    }

    return resultCity;
}
