/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* nums, int numsSize, int* returnSize) {
    int *ret = (int*)malloc(sizeof(int) * numsSize);
    int top = -1;

    for(int i = 0; i < numsSize; i++){
        if(top == -1 || nums[i] > 0){
            ret[++top] = nums[i];
        }
        else{
            while(top != -1 && abs(ret[top]) < abs(nums[i]) && ret[top] > 0) top--;
            if(top == -1 || ret[top] < 0){
                ret[++top] = nums[i];
            }
            else if(ret[top] + nums[i] == 0){
                top--;
            }
        }
    }

    *returnSize = top + 1;
    return ret;
}