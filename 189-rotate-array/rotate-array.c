void rotate(int* nums, int numsSize, int k) {
    int acc = k % numsSize;
    if(acc == 0) return;
    int *tmp1 = (int*)malloc(sizeof(int) * acc);
    int *tmp2 = (int*)malloc(sizeof(int) * (numsSize - acc));
    memcpy(tmp2, nums, sizeof(int) * (numsSize - acc));
    int index = 0;
    for(int i = numsSize - acc; i < numsSize; i++){
        tmp1[index++] = nums[i];
        if(index == acc) break;
    }
    memcpy(nums, tmp1, sizeof(int) * acc);
    memcpy(nums + acc, tmp2, sizeof(int) * (numsSize - acc));
    return;
}