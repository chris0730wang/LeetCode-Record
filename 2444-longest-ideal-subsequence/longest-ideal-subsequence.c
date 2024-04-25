#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int longestIdealString(char* s, int k) {
    if(strlen(s) == 0) return 0;
    int* dp = (int*)malloc(sizeof(int) * 26);
    for(int i = 0; i < 26; i++) dp[i] = 0;
    int ret = 0;
    for(int i = 0; i < strlen(s); i++){
        int val = s[i] - 'a';
        int tmp_max = 0;
        for(int j = MAX(0, val - k); j <= MIN(25, val + k); j++){
            tmp_max = MAX(tmp_max, dp[j]);
        }
        dp[val] = tmp_max + 1;
        ret = MAX(dp[val], ret);
    }
    
    return ret;
}