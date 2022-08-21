

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *res = (int*)malloc(2*sizeof(int));
    int temp;
    for(int i=0; i<numsSize; i++){
        temp = target - nums[i];
        for(int j=i+1; j<numsSize; j++){
            if(nums[j] == temp){
                res[0] = i;
                res[1] = j;
            }
        }
    }
    return res;
}