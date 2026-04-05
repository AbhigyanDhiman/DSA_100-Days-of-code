#include <stdbool.h>

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    int fresh = 0;
    int minutes = 0;
    
    int queue[rows * cols][2];
    int head = 0, tail = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 2) {
                queue[tail][0] = r;
                queue[tail][1] = c;
                tail++;
            } else if (grid[r][c] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0) return 0;

    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (head < tail && fresh > 0) {
        int size = tail - head;
        minutes++;
        
        for (int i = 0; i < size; i++) {
            int currR = queue[head][0];
            int currC = queue[head][1];
            head++;

            for (int d = 0; d < 4; d++) {
                int nextR = currR + dirs[d][0];
                int nextC = currC + dirs[d][1];

                if (nextR >= 0 && nextR < rows && nextC >= 0 && nextC < cols && grid[nextR][nextC] == 1) {
                    grid[nextR][nextC] = 2;
                    fresh--;
                    queue[tail][0] = nextR;
                    queue[tail][1] = nextC;
                    tail++;
                }
            }
        }
    }

    return (fresh == 0) ? minutes : -1;
}
