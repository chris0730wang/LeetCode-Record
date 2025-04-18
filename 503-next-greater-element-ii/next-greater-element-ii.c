/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* idxStack = (int*)malloc(sizeof(int) * numsSize);
    int* res = (int*)malloc(sizeof(int) * numsSize);
    int top = -1, i = 0;
    for(i = 0; i < 2 * numsSize; i++){
        int idx = i % numsSize;
        while(top >= 0 && nums[idx] > nums[idxStack[top]]){
            res[idxStack[top]] = nums[idx];
            top--;
        }
        if(i < numsSize){
            idxStack[++top] = idx;
            res[idx] = -1;
        }
    }
    
    free(idxStack);
    return res;
}