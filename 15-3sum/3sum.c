/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int **ret = (int **)malloc(sizeof(int *) * (numsSize * numsSize));
    *returnColumnSizes = (int *)malloc(sizeof(int) * (numsSize * numsSize));
    *returnSize = 0;
    for(int i = 0; i < numsSize - 2; i++){
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        int l = i + 1, r = numsSize - 1;
        while(l < r){
            int val = nums[i] + nums[l] + nums[r];
            if(val == 0){
                ret[*returnSize] = (int*)malloc(sizeof(int) * 3);
                ret[*returnSize][0] = nums[i];
                ret[*returnSize][1] = nums[l];
                ret[*returnSize][2] = nums[r];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                while (l < r && nums[l] == nums[l + 1]) {
                    l++;
                }
                while (l < r && nums[r] == nums[r - 1]) {
                    r--;
                }
                l++;
                r--;
            }
            else if(val < 0){
                l++;
            }
            else {
                r--;
            }
        }
    }
    return ret;
}