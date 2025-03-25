/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* ret = (int*)malloc(sizeof(int) * (*returnSize));
    int value = 1, zerotimes = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 0) {
            zerotimes++;
            continue;
        }
        value *= nums[i];
    }
    if(zerotimes > 1){
        return (int*)calloc(numsSize, sizeof(int));
    }
    for(int i = 0; i < numsSize; i++){
        if(zerotimes > 0 && nums[i] != 0) ret[i] = 0;
        else ret[i] = nums[i] == 0 ? value : value / nums[i];
    }
    return  ret;
}