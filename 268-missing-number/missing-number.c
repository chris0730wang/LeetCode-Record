int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int missingNumber(int* nums, int numsSize) {
    int index = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for(index = 0; index < numsSize; index++){
        if(nums[index] != index) break;
    }
    return index;
}