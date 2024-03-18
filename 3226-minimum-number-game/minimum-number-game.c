/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberGame(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *ret = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = 1; i < numsSize; i++){
        int tmp = nums[i];
        int j = i - 1;
        while(j >= 0 && tmp < nums[j]){
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = tmp; 
    }
    for(int i = 1; i < numsSize; i += 2){
        int tmp = nums[i];
        nums[i] = nums[i - 1];
        nums[i - 1] = tmp;
    }
    return nums;
}