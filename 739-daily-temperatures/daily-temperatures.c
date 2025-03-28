/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    *returnSize = temperaturesSize;
    int* res = (int*)calloc((*returnSize), sizeof(int));
    int* stack = (int*)malloc(sizeof(int) * (*returnSize));
    int index = 0;
    for(int i = temperaturesSize - 1; i >= 0; i--){
        for(int j = index - 1; j >= 0; j--){
            if(stack[j] > temperatures[i]){
                res[i] = index - j;
                break;
            }
            else if(stack[j] == temperatures[i]){
                res[i] = res[temperaturesSize - j - 1] == 0 ?  0 : res[temperaturesSize - j - 1] + temperaturesSize - j - 1 - i;
                break;
            }
        }
        stack[index] = temperatures[i];
        index++;
    }
    return res;
}