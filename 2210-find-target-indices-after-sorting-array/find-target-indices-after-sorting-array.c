/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b){
    return(*(int*)a - *(int*)b);
}
int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int firstpos = -1, lastpos = numsSize - 1;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > target && firstpos != -1){
            lastpos = i - 1;
            break;
        }
        if(nums[i] == target && firstpos == -1){
            firstpos = i;
        }
    }
    if(firstpos == -1) *returnSize = 0;
    else *returnSize = lastpos - firstpos + 1;
    int *ret = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < (*returnSize); i++){
        ret[i] = firstpos++;
    }
    return ret;
}