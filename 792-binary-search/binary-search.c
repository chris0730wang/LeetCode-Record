int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    int mid = (left + right) / 2;
    if(nums[left] == target) return left;
    if(nums[right] == target) return right;
    while(left < right){
        mid = (left + right) / 2;
        if(mid == left || mid == right) return -1;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    return -1;
}