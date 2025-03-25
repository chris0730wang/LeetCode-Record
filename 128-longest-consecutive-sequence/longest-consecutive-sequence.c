int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int longestConsecutive(int* nums, int numsSize) {
    if(numsSize <= 1) return numsSize;
    qsort(nums, numsSize, sizeof(int), cmp);
    int res = 1, tmp = 1;
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == nums[i - 1]){
            continue;
        }
        else if(nums[i] != nums[i - 1] + 1){
            res = res < tmp ? tmp : res;
            tmp = 1;
        }
        else{
            tmp++;
        }
    }
    return res < tmp ? tmp : res;
}