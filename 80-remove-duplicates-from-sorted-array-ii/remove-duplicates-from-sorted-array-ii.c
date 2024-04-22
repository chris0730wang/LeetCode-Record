int removeDuplicates(int* nums, int numsSize) {
    int index = 1;
    int times = 1;
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == nums[index - 1] && times == 1){
            nums[index++] = nums[i];
            times++;
        }
        else if(nums[i] != nums[index - 1]){
            nums[index++] = nums[i];
            times = 1;
        }
    }
    return index;
}