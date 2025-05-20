/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc(sizeof(int*) * (numsSize * numsSize));
    *returnColumnSizes = (int*)malloc(sizeof(int*) * (numsSize * numsSize));
    *returnSize = 0;
    int left, right, val;
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i = 0; i < numsSize - 2; i++){
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        if(nums[i] > 0) break;
        left = i + 1;
        right = numsSize - 1;
        while(left < right){
            val = nums[i] + nums[left] + nums[right];
            if(val == 0){
                res[(*returnSize)] = (int*)malloc(sizeof(int) * 3);
                res[(*returnSize)][0] = nums[i];
                res[(*returnSize)][1] = nums[left];
                res[(*returnSize)][2] = nums[right];
                (*returnColumnSizes)[(*returnSize)] = 3;
                (*returnSize)++;
                while(left < right && nums[left] == nums[left + 1]) left++;
                while(left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            }
            else if(val < 0){
                left++;
            }
            else{
                right--;
            }
        }
    }
    return res;
}