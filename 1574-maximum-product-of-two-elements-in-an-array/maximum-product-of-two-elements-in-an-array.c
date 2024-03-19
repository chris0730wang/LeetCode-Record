int maxProduct(int* nums, int numsSize) {
    for(int i = 1; i < numsSize; i++){
        int tmp = nums[i];
        int j = i - 1;
        while(j >= 0 && tmp < nums[j]){
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = tmp;
    }
    return (nums[numsSize - 1] - 1) * (nums[numsSize - 2] - 1);
}