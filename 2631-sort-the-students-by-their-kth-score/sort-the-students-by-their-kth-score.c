/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** sortTheStudents(int** score, int scoreSize, int* scoreColSize, int k, int* returnSize, int** returnColumnSizes) {
    *returnSize = scoreSize;
    *returnColumnSizes = scoreColSize;
    for(int i = 1; i < scoreSize; i++){
        int tmp = score[i][k];
        int *tmpStudent = score[i];
        int j = i - 1;
        while(j >= 0 && tmp > score[j][k]){
            score[j + 1] = score[j];
            j--;
        }
        score[j + 1] = tmpStudent;
    }
    return score;
}