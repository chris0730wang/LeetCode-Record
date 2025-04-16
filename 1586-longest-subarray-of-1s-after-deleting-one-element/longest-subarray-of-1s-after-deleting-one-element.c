int longestSubarray(int* nums, int numsSize) {
    int left = 0, zeroCount = 0, res = 0;
    
    for(int right = 0; right < numsSize; right++){
        if (nums[right] == 0) zeroCount++;

        while (zeroCount > 1) {
            if (nums[left] == 0) zeroCount--;
            left++;
        }

        // 長度是 right - left，但要刪一個元素
        res = (right - left) > res ? (right - left) : res;
    }
    return res;
}