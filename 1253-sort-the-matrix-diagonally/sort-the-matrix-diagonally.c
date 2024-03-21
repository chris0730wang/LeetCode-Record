/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = matSize;
    *returnColumnSizes = matColSize;
    int i = matSize - 1, j = 0;
    while(i >= 0 && j < (*matColSize)){
        int size = (matSize - i) < ((*matColSize) - j) ? (matSize - i) : ((*matColSize) - j);
        int *tmp = (int*)malloc(sizeof(int) * size);
        int idx = i, jdx = j, index = 0;
        while(idx < matSize && jdx < (*matColSize)){
            tmp[index++] = mat[idx++][jdx++];
        }
        qsort(tmp, size, sizeof(int), cmp);
        idx = i;
        jdx = j;
        for(index = 0; index < size; index++){
            mat[idx++][jdx++] = tmp[index];
        }
        i--;
        if(i < 0){
            i = 0;
            j++;
        }
    }
    return mat;
}