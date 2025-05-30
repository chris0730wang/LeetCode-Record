int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while(left <= right){
        int mid = left + ((right - left) / 2);
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;
}