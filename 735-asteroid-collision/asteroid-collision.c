/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* stack = (int*)malloc(sizeof(int) * asteroidsSize);
    int top = -1;

    for (int i = 0; i < asteroidsSize; i++) {
        int cur = asteroids[i];
        bool destroyed = false;

        while (top >= 0 && cur < 0 && stack[top] > 0) {
            if (stack[top] < -cur) {
                top--; // 當前小行星爆炸，繼續檢查前一個
            } else if (stack[top] == -cur) {
                top--; // 兩個都爆炸
                destroyed = true;
                break;
            } else {
                destroyed = true; // cur 被炸了
                break;
            }
        }

        if (!destroyed) {
            stack[++top] = cur;
        }
    }

    *returnSize = top + 1;
    return stack;
}