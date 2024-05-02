char* longestCommonPrefix(char** strs, int strsSize) {
    int min_len = INT_MAX;
    for(int i = 0; i < strsSize; i++){
        if(strlen(strs[i]) < min_len) min_len = strlen(strs[i]);
    }
    char* ret = (char*)malloc(sizeof(char) * (min_len + 1));
    ret[min_len] = '\0';
    for(int i = 0; i < min_len; i++){
        char s = strs[0][i];
        for(int j = 1; j < strsSize; j++){
            if(strs[j][i] != s){
                ret[i] = '\0';
                return ret;
            }
        }
        ret[i] = s;
    }
    return ret;

}