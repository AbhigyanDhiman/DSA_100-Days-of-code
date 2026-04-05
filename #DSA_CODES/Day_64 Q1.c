#include <stdio.h>

int queue[100], front = -1, rear = -1;
int visited[100];

void enqueue(int x) {
    if (rear == 99) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void bfs(int n, int adj[100][100], int s) {
    int i;
    
    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(s);
    visited[s] = 1;

    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, i, j, s;
    int adj[100][100];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &s);

    printf("BFS Traversal: ");
    bfs(n, adj, s);

    return 0;
}
