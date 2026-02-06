void moveZeroes(int* nums, int numsSize) {
    int lastNonZeroIndex = 0;

    for (int current = 0; current < numsSize; current++) {
        if (nums[current] != 0) {
            int temp = nums[lastNonZeroIndex];
            nums[lastNonZeroIndex] = nums[current];
            nums[current] = temp;
            
            lastNonZeroIndex++;
        }
    }
}
