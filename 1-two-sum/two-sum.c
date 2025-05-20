/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* res = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < numsSize - 1; i++){
        int chk = target - nums[i];
        for(int j = i + 1; j < numsSize; j++){
            if(nums[j] == chk){
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    return res;
}