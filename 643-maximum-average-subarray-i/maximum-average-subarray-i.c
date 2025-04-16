double findMaxAverage(int* nums, int numsSize, int k) {
    double dk = (double)k;
    double sum = 0.0, res;
    int left = 0, right = k - 1;
    for(int i = 0; i <= right; i++){
        sum += (double)nums[i];
    }
    res = sum / dk;
    while(right + 1 < numsSize){
        sum += nums[++right];
        sum -= nums[left++];
        res = sum / dk > res ? sum / dk : res;
    }
    return res;
}