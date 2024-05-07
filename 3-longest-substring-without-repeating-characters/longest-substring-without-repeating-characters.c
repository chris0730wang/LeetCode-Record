int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    if(len == 0) return 0;
    int* dp = (int*)malloc(sizeof(int) * len);
    int ret = 1;
    dp[0] = 1;
    for(int i = 1; i < len; i++){
        int idx = i - 1;
        for(int j = 0; j < dp[i - 1]; j++){
            if(s[idx] == s[i])break;
            idx--;
        }
        if(idx < i - dp[i - 1]) dp[i] = dp[i - 1] + 1;
        else dp[i] = i - idx;
        if(dp[i] > ret) ret = dp[i];
    }
    return ret;
}
