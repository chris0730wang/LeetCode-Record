int jump(int* nums, int numsSize) {
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    dp[0] = 0;
    for(int i = 1; i < numsSize; i++){
        dp[i] = -1;
    }
    for(int i = 0; i < numsSize; i++){
        int step = nums[i];
        for(int j = 1; j <= step; j++){
            int dest = i + j >= numsSize ? numsSize - 1 : i + j;
            dp[dest] = dp[dest] == -1 || dp[dest] > dp[i] + 1 ? dp[i] + 1 : dp[dest];
        }
    }
    return dp[numsSize-1];
}