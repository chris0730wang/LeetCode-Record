/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;
    int *ans = (int*)malloc(sizeof(int) * (*returnSize));
    *ans = 0;
    for(int i = 0; i <= n; i++){
        *(ans + i) = *(ans + i / 2) + i % 2; //十進位轉二進位 : 一直除以二直到商是0，所以就是i一半的值加上i%2
    }
    return ans;
}