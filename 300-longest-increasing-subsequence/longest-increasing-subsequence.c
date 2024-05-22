int lengthOfLIS(int* nums, int numsSize) {
    if(numsSize == 1) return 1;
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    dp[0] = 1;
    int ret = 0;
    for(int i = 1; i < numsSize; i++){
        dp[i] = 1;
        for(int j = i; j >= 0; j--){
            if(nums[j] < nums[i]){
                dp[i] = dp[j] + 1 > dp[i] ? dp[j] + 1 : dp[i];
            }
        }
        ret = dp[i] > ret ? dp[i] : ret;
    }
    return ret;
}