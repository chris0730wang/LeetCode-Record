/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize) {
    *returnSize = lSize;
    bool *ret = (bool*)malloc(sizeof(bool) * (*returnSize));
    for(int i = 0; i < lSize; i++){
        int *tmp = (int*)malloc(sizeof(int) * (r[i] - l[i] + 1));
        int idx = 0;
        for(int j = l[i]; j <= r[i]; j++){
            tmp[idx] = nums[j];
            idx++;
        }
        qsort(tmp, r[i] - l[i] + 1, sizeof(int), cmp);
        int gap = tmp[1] - tmp[0];
        ret[i] = true;
        for(int j = 1; j < r[i] - l[i] + 1; j++){
            if(tmp[j] - tmp[j - 1] != gap){
                ret[i] = false;
                break;
            }
        }
    }
    return ret;
}