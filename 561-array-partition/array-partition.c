int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}
int arrayPairSum(int* nums, int numsSize) {
    int ret = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    // for(int i = 1; i < numsSize; i++){
    //     int tmp = nums[i];
    //     int j = i - 1;
    //     while(j >= 0 && tmp < nums[j]){
    //         nums[j + 1] = nums[j];
    //         j--;
    //     }
    //     nums[j + 1] = tmp;
    // }
    for(int i = 0; i < numsSize; i+=2){
        ret += nums[i];
    }
    return ret;
}