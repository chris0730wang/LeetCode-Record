int strStr(char* haystack, char* needle) {
    int hlen = strlen(haystack);
    int nlen = strlen(needle);
    if(hlen < nlen) return -1;
    for(int i = 0; i <= hlen - nlen; i++){
        int index = 0;
        if(haystack[i] == needle[0]){
            for(int j = 0; j < nlen; j++){
                if(haystack[i + j] == needle[j] && j == nlen - 1) return i;
                if(haystack[i + j] != needle[j]) break;
            }
        }
    }
    return -1;
}