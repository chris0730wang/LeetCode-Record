int maxSumAfterPartitioning(int* arr, int arrSize, int k) {
    int* dp = (int*)malloc(sizeof(int) * (arrSize + 1));
    dp[0] = 0;
    for(int i = 1; i <= arrSize; i++){
        int currMax = 0;
        for(int j = 1; j <= k && i - j >= 0; j++){
            currMax = arr[i - j] > currMax ? arr[i - j] : currMax;
            dp[i] = dp[i] > dp[i - j] + (currMax * j) ? dp[i] : dp[i - j] + (currMax * j);
        }
    }
    return dp[arrSize];
}