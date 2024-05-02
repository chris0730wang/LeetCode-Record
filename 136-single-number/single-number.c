int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int singleNumber(int* nums, int numsSize) {
    if(numsSize == 1) return nums[0];
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i = 0; i < numsSize - 1; i += 2){
        if(nums[i] != nums[i + 1]) return nums[i];
    }
    return nums[numsSize - 1];
}