

char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0)return "";
    if(strsSize == 1)return strs[0];
    int len = 0, min = strlen(strs[0]);
    for(int i=1; i<strsSize; i++){
        min = strlen(strs[i]) < min ? strlen(strs[i]) : min;
    }
    for(int col=0; col<min; col++){
        for(int row=0; row<strsSize - 1; row++){
            if(strs[row][col] == strs[row+1][col]){
                if(row == strsSize - 2) len++;
            }else{
                goto br;
            }
        }
    }
    
    br:
    
    if(len>0){
        char* result = (char*)malloc(len*sizeof(int));
        strs[0][len] = '\0';
        strcpy(result, strs[0]);
        return result;
    }
    
    return "";
}