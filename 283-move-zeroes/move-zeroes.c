void moveZeroes(int* nums, int numsSize) {
    int index = 0;  // 指向下一個要放非 0 元素的位置

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[index++] = nums[i];
        }
    }

    // 將剩下的都設為 0
    while (index < numsSize) {
        nums[index++] = 0;
    }
}