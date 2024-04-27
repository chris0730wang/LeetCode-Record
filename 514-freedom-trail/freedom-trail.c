// 定義最大字串長度
#define MAXLEN 1000

int min(int a, int b) {
    return a < b ? a : b;
}

int findRotateSteps(char *ring, char *key) {
    int ringLen = strlen(ring);
    int keyLen = strlen(key);
    
    // 創建二維 DP 表，DP[i][j] 表示第 i 個齒輪和第 j 個鍵匙之間的最小步數
    int DP[keyLen + 1][ringLen];
    memset(DP, 0, sizeof(DP));

    // 以鍵匙為主，開始 DP
    for (int i = keyLen - 1; i >= 0; i--) {
        for (int j = 0; j < ringLen; j++) {
            // 初始設定最大值
            DP[i][j] = 1 << 30;

            // 對於每個齒輪的位置，找到所有鍵匙對應的位置，計算最小步數
            for (int k = 0; k < ringLen; k++) {
                if (ring[k] == key[i]) {
                    int diff = abs(j - k); // 計算兩個位置之間的距離
                    int step = min(diff, ringLen - diff); // 取最小的步數
                    DP[i][j] = min(DP[i][j], step + DP[i + 1][k]); // 更新最小步數
                }
            }
        }
    }

    // 返回從第一個鍵匙開始的最小步數
    return DP[0][0] + keyLen;
}
