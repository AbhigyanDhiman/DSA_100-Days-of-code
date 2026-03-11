#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    
    int *result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int *dq = (int*)malloc(sizeof(int) * numsSize);
    
    int front = 0, rear = -1;
    *returnSize = numsSize - k + 1;
    int idx = 0;

    for(int i = 0; i < numsSize; i++) {

        while(front <= rear && dq[front] <= i - k)
            front++;

        while(front <= rear && nums[dq[rear]] < nums[i])
            rear--;

        dq[++rear] = i;

        if(i >= k - 1)
            result[idx++] = nums[dq[front]];
    }

    return result;
}
