/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b){
    int* intA = *(int**)a;
    int* intB = *(int**)b;
    return intA[0] - intB[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int** res = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = malloc(sizeof(int) * intervalsSize);
    *returnSize = 0;
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int start = intervals[0][0], end = intervals[0][1];
    for(int i = 1; i < intervalsSize; i++){
        if(intervals[i][0] >= start && intervals[i][0] <= end){
            end = intervals[i][1] > end ? intervals[i][1] : end;
        }
        else{
            res[(*returnSize)] = (int*)malloc(sizeof(int) * 2);
            (*returnColumnSizes)[(*returnSize)] = 2;
            res[(*returnSize)][0] = start;
            res[(*returnSize)][1] = end;
            start = intervals[i][0];
            end = intervals[i][1];
            (*returnSize)++;
        }
    }
    res[(*returnSize)] = (int*)malloc(sizeof(int) * 2);
    (*returnColumnSizes)[(*returnSize)] = 2;
    res[(*returnSize)][0] = start;
    res[(*returnSize)][1] = end;
    (*returnSize)++;
    return res;
}