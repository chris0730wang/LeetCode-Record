/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *ret = (int*)malloc(sizeof(int) * (*returnSize));
    int cnt = 0;
    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < numsSize; j++){
            if(nums[j] < nums[i]) cnt++; 
        }
        ret[i] = cnt;
        cnt = 0;
    }
    return ret;
}