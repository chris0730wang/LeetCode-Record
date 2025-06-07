/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void backtrack(int* candidates, int candidatesSize, int target,
               int* temp, int tempSize, int start,
               int** result, int* returnSize, int* returnColumnSizes) {
    
    if(target == 0){
        returnColumnSizes[(*returnSize)] = tempSize;
        result[(*returnSize)] = (int*)malloc(sizeof(int) * tempSize);
        for(int i = 0; i < tempSize; i++){
            result[(*returnSize)][i] = temp[i];
        }
        (*returnSize)++;
        return;
    }

    for(int i = start; i < candidatesSize; i++){
        if (candidates[i] > target) continue;
        temp[tempSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], temp, tempSize + 1, i,
              result, returnSize, returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** result = malloc(sizeof(int*) * 1000);  // 最多解數量預估
    *returnColumnSizes = malloc(sizeof(int) * 1000);
    *returnSize = 0;
    
    int* temp = malloc(sizeof(int) * target);  // 最多 target 層深度
    backtrack(candidates, candidatesSize, target, temp, 0, 0,
              result, returnSize, *returnColumnSizes);
    free(temp);
    return result;
}