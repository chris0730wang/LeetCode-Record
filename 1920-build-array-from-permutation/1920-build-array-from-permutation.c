

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *res = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i=0; i<numsSize; i++){
        res[i] = nums[nums[i]];
    }
    return res;
}