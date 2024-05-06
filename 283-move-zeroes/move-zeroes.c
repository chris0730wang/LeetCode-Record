void moveZeroes(int* nums, int numsSize) {
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 0){
            int idx = i + 1;
            while(idx < numsSize){
                if(nums[idx++] == 0) continue;
                break;
            }
            if(idx - 1 == numsSize) break;
            else{
                nums[i] = nums[idx - 1];
                nums[idx - 1] = 0;
            }
        }
    }
}