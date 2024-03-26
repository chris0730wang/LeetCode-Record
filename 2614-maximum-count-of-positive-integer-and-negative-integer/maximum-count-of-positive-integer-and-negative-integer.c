int maximumCount(int* nums, int numsSize) {
    int n = 0;
    int p = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 0) continue;
        else if(nums[i] > 0){
            p = numsSize - i;
            break;
        }
        else{
            n++;
        }
    }
    return p > n ? p : n;
}