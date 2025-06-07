char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len < 2) return strdup(s); // 長度 0 或 1 直接回傳

    bool dp[len][len];
    memset(dp, 0, sizeof(dp));

    int maxLen = 1;
    int start = 0;

    // 每個單字元都是回文
    for (int i = 0; i < len; i++) {
        dp[i][i] = true;
    }

    // 由下往上、由左往右填表（i 從大到小，j 從 i 到 len-1）
    for(int i = len - 1; i >= 0; i--){
        for(int j = i + 1; j < len; j++){
            if(s[i] == s[j]){
                if(j - i == 1 || dp[i + 1][j - 1] == true){
                    dp[i][j] = true;
                    if(j - i + 1 > maxLen){
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }
    }

    char *res = (char *)malloc(sizeof(char) * (maxLen + 1));
    strncpy(res, s + start, maxLen);
    res[maxLen] = '\0';
    return res;
}