int strStr(char* haystack, char* needle) {
    int len_h = strlen(haystack);
    int len_n = strlen(needle);
    for(int i = 0; i < len_h; i++){
        if(haystack[i] != needle[0]) continue;
        int index = i;
        for(int j = 0; j < len_n; j++){
            if(haystack[index++] != needle[j]) break;
            if(j == len_n - 1) return i;
        }
    }
    return -1;
}