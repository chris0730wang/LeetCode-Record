/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    *returnSize = namesSize;
    for(int i = 1; i < heightsSize; i++){
        char *tmp = names[i];
        int tmpH = heights[i];
        int j = i - 1;
        while(j >= 0 && tmpH > heights[j]){
            heights[j + 1] = heights[j];
            names[j + 1] = names[j];
            j--;
        }
        heights[j + 1] = tmpH;
        names[j + 1] = tmp;
    }
    return names;
}