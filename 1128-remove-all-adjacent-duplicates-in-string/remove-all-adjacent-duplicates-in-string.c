char* removeDuplicates(char* s) {
    int len = strlen(s);
    char* res = (char*)malloc(sizeof(char) * len);
    int top = -1;
    for(int i = 0; i < len; i++){
        if(top >= 0 && res[top] == s[i]){
            top--;
        }
        else{
            res[++top] = s[i];
        }
    }
    res[++top] = '\0';
    return res;
}