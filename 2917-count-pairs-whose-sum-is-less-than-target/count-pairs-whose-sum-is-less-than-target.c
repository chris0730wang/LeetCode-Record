int countPairs(int* nums, int numsSize, int target){
    int sum, count = 0;
    for(int i = 0; i < numsSize - 1; i++){
        for(int j = i + 1; j < numsSize; j++){
            sum = nums[i] + nums[j];
            if(sum < target) count++;
        }
    }
    return count;
}