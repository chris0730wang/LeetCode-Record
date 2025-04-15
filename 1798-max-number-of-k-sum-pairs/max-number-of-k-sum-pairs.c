int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int maxOperations(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), cmp);
    int left = 0, right = numsSize - 1, res = 0;
    while(left < right){
        int sum = nums[left] + nums[right];
        if(sum < k){
            left++;
        }
        else if(sum > k){
            right--;
        }
        else{
            res++;
            left++;
            right--;
        }
    }
    return res;
}