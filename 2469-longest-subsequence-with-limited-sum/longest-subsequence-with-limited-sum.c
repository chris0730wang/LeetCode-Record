/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b){
    return(*(int*)a - *(int*)b);
}
int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    *returnSize = queriesSize;
    int *ret = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < queriesSize; i++){
        int idx = 0;
        int tmp = queries[i];
        bool flag = false;
        while(tmp >= 0 && idx < numsSize){
            if(tmp < nums[idx]) break;
            tmp -= nums[idx];
            idx++;
        }
        ret[i] = idx;
    }
    return ret;
}