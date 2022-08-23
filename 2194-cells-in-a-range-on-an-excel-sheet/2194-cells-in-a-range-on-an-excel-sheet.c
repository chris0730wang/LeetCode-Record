

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** cellsInRange(char * s, int* returnSize){
    char ch, j;
    int i;
    int row = s[4] - s[1] + 1, col = s[3] - s[0] + 1;
    *returnSize = row * col;
    char **ret = (char**)malloc(sizeof(char*) * (*returnSize));
    for (i = 0; i < (*returnSize); ++i) {
        ret[i] = (char*) malloc(3 * sizeof(char));
    }
    i = 0;
    for (ch = s[0]; ch <= s[3]; ++ch) {
        for (j = s[1]; j <= s[4]; ++j) {
            ret[i][0] = ch;
            ret[i][1] = j;
            ret[i][2] = '\0';
            i++;
        }
    }
    return ret;
}