int maxProduct(int* nums, int numsSize) {
    int** dp = (int**)malloc(sizeof(int*) * numsSize);
    for(int i = 0; i < numsSize; i++) dp[i] = (int*)malloc(sizeof(int) * 2);
    for(int i = 0; i < 2; i++) dp[0][i] = nums[0];
    int ret = nums[0];
    for(int i = 1; i < numsSize; i++){
        int min = INT_MAX, max = INT_MIN;
        for(int j = 0; j < 2; j++){
            int tmp = dp[i - 1][j] * nums[i];
            min = tmp < min ? tmp : min;
            max = tmp > max ? tmp : max;
        }
        min = nums[i] < min ? nums[i] : min;
        max = nums[i] > max ? nums[i] : max;
        dp[i][0] = min;
        dp[i][1] = max;
        ret = max > ret ? max : ret;
    }
    return ret;
}