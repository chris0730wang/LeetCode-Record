
void moveZeroes(int* nums, int numsSize){
    int *zero, *non_zero;
    int *index = nums;
    printf("%d", *index);
    for(int i=0; i<numsSize; i++){
        if(nums[i] == 0){
            zero = &nums[i];
            for(int j=i+1; j<numsSize; j++){
                if(nums[j] != 0){
                    non_zero = &nums[j];
                    int temp = nums[i];
                    *zero = nums[j];
                    *non_zero = temp;
                    break;
                }
            }
        }
    }
}