int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    while(left <= right){
        int tmp = (left + right) / 2;
        if(nums[tmp] == target) return tmp;
        else if(nums[tmp] < target) left = tmp + 1;
        else if(nums[tmp] > target) right = tmp - 1;
    }
    return -1;
}