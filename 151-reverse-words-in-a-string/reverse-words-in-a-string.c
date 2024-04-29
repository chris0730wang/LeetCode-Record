char* reverseWords(char* s) {
    int len = strlen(s);
    char* ret = (char*)malloc(sizeof(char) * (len + 1));
    ret[len] = '\0';
    int index = 0;
    for(int i = len - 1; i >= 0; i--){
        if(s[i] == ' ') {
            ret[index++] = ' ';
            continue;
        }
        int right = i, left = i;
        while(left > 0 && s[left - 1] != ' ') left--;
        for(int j = left; j <= right; j++){
            ret[index++] = s[j];
        }
        i = left;
    }

    index = 0;
    for(int i = 0; ret[i]; i++){
        if(ret[i] != ' ' || (i > 0 && ret[i - 1] != ' ')){
            ret[index++] = ret[i];
        }
    }
    if(ret[index - 1] == ' ') ret[index - 1] = '\0';
    else ret[index] = '\0';

    return ret;
}