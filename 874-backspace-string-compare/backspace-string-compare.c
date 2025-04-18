bool backspaceCompare(char* s, char* t) {
    char* sStack = (char*)malloc(sizeof(char) * 200);
    char* tStack = (char*)malloc(sizeof(char) * 200);
    int sTop = -1, tTop = -1;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '#') sTop = sTop < 0 ? sTop : sTop - 1;
        else sStack[++sTop] = s[i];
    }
    for(int i = 0; i < strlen(t); i++){
        if(t[i] == '#') tTop = tTop < 0 ? tTop : tTop - 1;
        else tStack[++tTop] = t[i];
    }
    if(sTop != tTop) return false;
    for(int i = 0; i < sTop + 1; i++){
        if(sStack[i] != tStack[i]) return false;
    }
    return true;
}