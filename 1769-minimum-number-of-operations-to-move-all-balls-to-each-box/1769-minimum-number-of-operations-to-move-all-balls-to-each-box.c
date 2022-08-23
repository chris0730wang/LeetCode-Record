

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minOperations(char * boxes, int* returnSize){
    *returnSize = strlen(boxes);
    int *res = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i=0; i<(*returnSize); i++){
        res[i] = 0;
        char *now_box = &boxes[i];
        char *right = now_box;
        char *left = now_box;
        while(*right){
            res[i] += (*right - '0') * abs(right - now_box);
            *right++;
        }
        while(left != boxes - 1){
            res[i] += (*left - '0') * abs(left - now_box);
            *left--;
        }
    }
    return res;
}