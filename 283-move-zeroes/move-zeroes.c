void moveZeroes(int* nums, int numsSize) {
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 0){
            int j = i + 1;
            while(j < numsSize && nums[j] == 0) j++;
            if(j == numsSize) return;
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
    return;
}