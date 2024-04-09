int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int minimumSize(int* nums, int numsSize, int maxOperations) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int l = 1, r = nums[numsSize - 1] + 1;
    while(l < r){
        int m = l + (r - l) / 2;
        int ops = 0; // 執行divide次數
        for(int i = 0; i < numsSize; i++){
            int tmp = nums[i] % m == 0 ? nums[i] / m - 1 : nums[i] / m + 1 - 1;
            ops += tmp;
        }
        if(ops <= maxOperations){
            r = m;
        }else{
            l = m + 1;
        }
    }
    return l;
}