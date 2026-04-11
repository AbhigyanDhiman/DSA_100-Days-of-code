#include <stdio.h>
#include <limits.h>
#include <string.h>

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    // Distance array initialized to a large value (infinity)
    int dist[n];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    // Run relaxation k+1 times (k stops means k+1 edges max)
    for (int i = 0; i <= k; i++) {
        int temp[n];
        memcpy(temp, dist, sizeof(dist));

        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int price = flights[j][2];

            // If the starting city of this flight is reachable
            if (dist[u] != INT_MAX) {
                if (dist[u] + price < temp[v]) {
                    temp[v] = dist[u] + price;
                }
            }
        }
        // Update the main distance array after checking all flights for this 'stop' level
        memcpy(dist, temp, sizeof(dist));
    }

    return (dist[dst] == INT_MAX) ? -1 : dist[dst];
}
