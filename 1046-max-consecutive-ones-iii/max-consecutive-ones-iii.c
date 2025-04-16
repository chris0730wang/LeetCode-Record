int longestOnes(int* nums, int numsSize, int k) {
    int left = 0, res = 0;
    for (int right = 0; right < numsSize; right++) {
        if (nums[right] == 0) k--;

        while (k < 0) {
            if (nums[left] == 0) k++;
            left++;
        }

        if (right - left + 1 > res) {
            res = right - left + 1;
        }
    }
    return res;
}