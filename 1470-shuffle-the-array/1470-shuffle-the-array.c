

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    *returnSize = numsSize;
    int *res = (int*)malloc(sizeof(int) * (*returnSize));
    int index = 0;
    for(int i=0; i<n; i++){
        res[index++] = nums[i];
        res[index++] = nums[i+n];
    }
    return res;
}