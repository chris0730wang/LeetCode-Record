/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    *returnSize = 2;
    int* res = (int*)malloc(sizeof(int) * (*returnSize));
    int left = 0, right = numbersSize - 1;
    while(left < right){
        int val = numbers[left] + numbers[right];
        if(val == target){
            res[0] = left + 1;
            res[1] = right + 1;
            break;
        }
        else if(val > target){
            right--;
        }
        else{
            left++;
        }
    }
    return res;
}