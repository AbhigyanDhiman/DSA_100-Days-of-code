#include <stdio.h>

int maxLen(int arr[], int n) {
    int max_l = 0;
    for (int i = 0; i < n; i++) {
        int curr_sum = 0;
        for (int j = i; j < n; j++) {
            curr_sum += arr[j];
            if (curr_sum == 0) {
                int current_len = j - i + 1;
                if (current_len > max_l) {
                    max_l = current_len;
                }
            }
        }
    }
    return max_l;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", maxLen(arr, n));

    return 0;
}
