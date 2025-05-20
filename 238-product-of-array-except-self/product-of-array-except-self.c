/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* res = (int*)malloc(sizeof(int) * (*returnSize));
    int val = 1;
    res[0] = 1;
    for(int i = 1; i < numsSize; i++){
        val *= nums[i - 1];
        res[i] = val;
    }
    val = 1;
    for(int i = numsSize - 2; i >= 0; i--){
        val *= nums[i + 1];
        res[i] *= val;
    }
    return res;
}