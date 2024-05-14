int maxSubArray(int* nums, int numsSize) {
    if(numsSize == 1) return nums[0];
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    dp[0] = nums[0];
    int max = dp[0];
    for(int i = 1; i < numsSize; i++){
        if(dp[i - 1] < 0) dp[i] = nums[i];
        else dp[i] = dp[i - 1] + nums[i];
        max = dp[i] > max ? dp[i] : max;
    }
    return max;
}