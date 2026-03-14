#include <stdio.h>

int main() {
    int n, i;
    int queue[100], stack[100];
    int top = -1;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    for(i = 0; i < n; i++) {
        stack[++top] = queue[i];
    }

    while(top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
