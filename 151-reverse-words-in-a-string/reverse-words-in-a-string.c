char* reverseWords(char* s) {
    int len = strlen(s);
    char* res = (char*)malloc(sizeof(char) * (len + 2));
    char* temp = (char*)malloc(sizeof(char) * (len + 1));
    int index = 0, idx = 0;
    res[0] = '\0';
    for(int i = len - 1; i >= 0; i--){
        if(s[i] == ' ' && index != 0){
            res[idx++] = ' ';
            for(int j = index - 1; j >= 0; j--){
                res[idx++] = temp[j];
            }
            temp[0] = '\0';
            index = 0;
        }
        else if(s[i] == ' ') {
            continue;
        }
        else {
            temp[index++] = s[i];
        }
    }
    if(index != 0){
        res[idx++] = ' ';
        for(int j = index - 1; j >= 0; j--){
            res[idx++] = temp[j];
        }
    }
    res[idx] = '\0';
    return res + 1;
}