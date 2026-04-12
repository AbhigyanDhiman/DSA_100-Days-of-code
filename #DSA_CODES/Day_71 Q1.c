#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int hashTable[m];
    for (int i = 0; i < m; i++) {
        hashTable[i] = -1;
    }

    char op[10];
    int key;

    for (int j = 0; j < n; j++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            for (int i = 0; i < m; i++) {
                int index = (key + i * i) % m;
                if (hashTable[index] == -1) {
                    hashTable[index] = key;
                    break;
                }
            }
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            int found = 0;
            for (int i = 0; i < m; i++) {
                int index = (key + i * i) % m;
                if (hashTable[index] == key) {
                    found = 1;
                    break;
                }
                if (hashTable[index] == -1) {
                    break;
                }
            }
            if (found) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }

    return 0;
}
