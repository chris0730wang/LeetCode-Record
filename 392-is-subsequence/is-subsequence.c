bool isSubsequence(char* s, char* t) {
    int index = 0;
    int slen = strlen(s), tlen = strlen(t);
    if(slen == NULL) return true;
    for(int i = 0; i < tlen; i++){
        if(t[i] == s[index]) index++;
        if(index == slen) return true;;
    }
    return false;
}