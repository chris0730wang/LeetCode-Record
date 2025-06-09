int rob(int* nums, int numsSize) {
    if(numsSize == 1) return nums[0];
    if(numsSize == 2) return nums[1] > nums[0] ? nums[1] : nums[0];
    if(numsSize == 3) return nums[0] + nums[2] > nums[1] ? nums[0] + nums[2] : nums[1];
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = nums[0] + nums[2];
    int max = dp[2] > dp[1] ? dp[2] : dp[1];
    for(int i = 3; i < numsSize; i++){
        dp[i] = dp[i - 2] > dp[i - 3] ? dp[i - 2] + nums[i] : dp[i - 3] + nums[i];
        max = dp[i] > max ? dp[i] : max;
    }
    return max;
}