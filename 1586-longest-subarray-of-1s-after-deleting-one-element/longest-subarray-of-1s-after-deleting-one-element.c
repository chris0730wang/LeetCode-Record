int longestSubarray(int* nums, int numsSize) {
    int zeroidx = -1;
    bool zerochk = false;
    int left = 0, res = 0;
    for(int right = 0; right < numsSize; right++){
        if(zerochk && nums[right] == 0){
            if(right - left - 1 > res){
                res = right - left - 1;
            }
            left = zeroidx + 1;
            zeroidx = right;
        }

        if(nums[right] == 0) {
            zeroidx = zerochk ? zeroidx : right;
            zerochk = true;
        }

    }
    return res > numsSize - left - 1 ? res : numsSize - left - 1;
}