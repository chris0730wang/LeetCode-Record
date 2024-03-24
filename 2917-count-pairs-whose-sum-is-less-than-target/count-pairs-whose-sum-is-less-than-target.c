int cmp(const void *a, const void *b){
    return (*(int*) a - *(int*)b);
}
int countPairs(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), cmp);
    int left = 0;
    int right = numsSize - 1;
    int ret = 0;
    while(left < right){
        if(nums[left] + nums[right] >= target){
            right--;
        }
        else{
            ret += right - left;
            left++;
            right = numsSize - 1;
        }
    }
    return ret;
}