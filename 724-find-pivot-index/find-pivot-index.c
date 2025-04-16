int pivotIndex(int* nums, int numsSize) {
    int right = 0, left = 0, res = -1;
    for(int i = 0; i < numsSize; i++) right += nums[i];
    if(right - nums[0] == 0) return 0;
    for(int i = 0; i < numsSize - 1; i++){
        left += nums[i];
        right -= nums[i];
        if(left == right - nums[i+1]) return i+1;
    }
    return res;
}