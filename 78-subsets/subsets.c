/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int max_subsets = 1 << numsSize;
    int** ret = (int**)malloc(sizeof(int*) * max_subsets);
    *returnColumnSizes = (int*)malloc(sizeof(int) * max_subsets);
    ret[0] = (int*)malloc(sizeof(int) * 0);
    (*returnColumnSizes)[0] = 0;
    *returnSize = 1;
    int index = 1;
    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < (*returnSize); j++){
            (*returnColumnSizes)[index] = (*returnColumnSizes)[j] + 1;
            ret[index] = (int*)malloc(sizeof(int) * (*returnColumnSizes)[index]);
            //memcpy(ret[index], ret[j], (*returnColumnSizes)[j]);
            for(int k = 0; k < (*returnColumnSizes)[j]; k++) ret[index][k] = ret[j][k];
            ret[index][(*returnColumnSizes)[j]] = nums[i];
            index++;
        }
        (*returnSize) *= 2;
    }
    return ret;
}
