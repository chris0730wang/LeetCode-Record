/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int** ret = (int**)malloc(sizeof(int*) * (intervalsSize + 1));
    int prevStart, prevEnd;
    bool flag = false;
    int i = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int*) * (intervalsSize + 1));
    *returnSize = 0;
    (*returnColumnSizes)[(*returnSize)] = 2;
    if(intervalsSize == 0){
        ret[(*returnSize)] = newInterval;
        (*returnSize)++;
        return ret;
    }
    if(newInterval[0] < intervals[0][0]){
        ret[0] = newInterval;
        i = 0;
    }
    else{
        ret[0] = intervals[0];
        i = 1;
    }
    prevStart = ret[(*returnSize)][0];
    prevEnd = ret[(*returnSize)][1];
    (*returnSize)++;
    for(int i = i; i < intervalsSize; i++){
        if(!flag && newInterval[0] <= intervals[i][0]){
            if(newInterval[0] <= prevEnd){
                ret[(*returnSize) - 1][0] = prevStart < newInterval[0] ? prevStart : newInterval[0];
                ret[(*returnSize) - 1][1] = prevEnd > newInterval[1] ? prevEnd : newInterval[1];
                prevStart = ret[(*returnSize) - 1][0];
                prevEnd = ret[(*returnSize) - 1][1];
            }
            else{
                (*returnColumnSizes)[(*returnSize)] = 2;
                ret[(*returnSize)] = newInterval;
                (*returnSize)++;
                prevStart = ret[(*returnSize) - 1][0];
                prevEnd = ret[(*returnSize) - 1][1];
            }
            i--;
            flag = true;
        }
        else{
            if(intervals[i][0] <= prevEnd){
                ret[(*returnSize) - 1][0] = prevStart < intervals[i][0] ? prevStart : intervals[i][0];
                ret[(*returnSize) - 1][1] = prevEnd > intervals[i][1] ? prevEnd : intervals[i][1];
                prevStart = ret[(*returnSize) - 1][0];
                prevEnd = ret[(*returnSize) - 1][1];
            }
            else{
                (*returnColumnSizes)[(*returnSize)] = 2;
                ret[(*returnSize)] = intervals[i];
                (*returnSize)++;
                prevStart = ret[(*returnSize) - 1][0];
                prevEnd = ret[(*returnSize) - 1][1];
            }
        }
    }
    if(!flag){
        if(newInterval[0] <= prevEnd){
            ret[(*returnSize) - 1][0] = prevStart < newInterval[0] ? prevStart : newInterval[0];
            ret[(*returnSize) - 1][1] = prevEnd > newInterval[1] ? prevEnd : newInterval[1];
            prevStart = ret[(*returnSize) - 1][0];
            prevEnd = ret[(*returnSize) - 1][1];
        }
        else{
            (*returnColumnSizes)[(*returnSize)] = 2;
            ret[(*returnSize)] = newInterval;
            prevStart = ret[(*returnSize) - 1][0];
            prevEnd = ret[(*returnSize) - 1][1];
            (*returnSize)++;
        }
    }
    return ret;
}