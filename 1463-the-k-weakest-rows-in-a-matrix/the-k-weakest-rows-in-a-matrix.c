/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
   int *tmp = (int*)malloc(sizeof(int) * matSize);
   int *tmpIndex = (int*)malloc(sizeof(int) * matSize);
   for(int i = 0; i < matSize; i++){
        int idx = 0;
        for(int j = 0; j < (*matColSize); j++){
            if(mat[i][j] != 1) break;
            idx++;
        }
        tmp[i] = idx;
        tmpIndex[i] = i;
   }
   *returnSize = k;
   int *ret = (int*)malloc(sizeof(int) * (*returnSize));
   for(int i = 1; i < matSize; i++){
        int num = tmp[i];
        int j = i - 1;
        while(j >= 0 && num < tmp[j]){
            tmp[j + 1] = tmp[j];
            tmpIndex[j + 1] = tmpIndex[j];
            j--;
        }
        tmp[j + 1] = num;
        tmpIndex[j + 1] = i;
   }
   for(int i = 0; i < k; i++){
        ret[i] = tmpIndex[i];
   }
   return ret;
}