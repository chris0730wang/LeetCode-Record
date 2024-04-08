/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *ret = (int*)malloc(sizeof(int) * (*returnSize));
    ret[0] = -1;
    ret[1] = -1;
    int l = 0, r = numsSize - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(nums[m] < target) l = m + 1;
        else if (nums[m] > target) r = m - 1;
        else {
            if(m == 0 || (m > 0 && nums[m] != nums[m-1])){
                ret[0] = m;
                break;
            }
            else{
                r = m - 1;
            }
        }
    }
    l = 0, r = numsSize - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(nums[m] < target) l = m + 1;
        else if (nums[m] > target) r = m - 1;
        else {
            if(m == numsSize - 1 || (m < numsSize - 1 && nums[m] != nums[m+1])){
                ret[1] = m;
                break;
            }
            else{
                l = m + 1;
            }
        }
    }
    return ret;
}