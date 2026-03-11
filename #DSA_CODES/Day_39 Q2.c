#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    int freq;
};

int cmp(const void *a, const void *b) {
    struct Node *x = (struct Node *)a;
    struct Node *y = (struct Node *)b;
    return y->freq - x->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {

    struct Node* arr = (struct Node*)malloc(sizeof(struct Node) * numsSize);
    int size = 0;

    for(int i = 0; i < numsSize; i++) {
        int found = 0;

        for(int j = 0; j < size; j++) {
            if(arr[j].num == nums[i]) {
                arr[j].freq++;
                found = 1;
                break;
            }
        }

        if(!found) {
            arr[size].num = nums[i];
            arr[size].freq = 1;
            size++;
        }
    }

    qsort(arr, size, sizeof(struct Node), cmp);

    int* result = (int*)malloc(sizeof(int) * k);

    for(int i = 0; i < k; i++) {
        result[i] = arr[i].num;
    }

    *returnSize = k;
    return result;
}
