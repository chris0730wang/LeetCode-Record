bool backspaceCompare(char* s, char* t) {
    int s_len = strlen(s);
    int t_len = strlen(t);
    char* s_ret = (char*)malloc(sizeof(char) * (s_len + 1));
    char* t_ret = (char*)malloc(sizeof(char) * (t_len + 1));
    s_ret[s_len] = '\0';
    t_ret[t_len] = '\0';
    int i = s_len - 1;
    int idx = 0;
    int del = 0;
    while(i >= 0){
        if(s[i] == '#'){
            del++;
        }
        else if(del > 0){
            del--;
        }
        else{
            s_ret[idx++] = s[i];
        }
        i--;
    }
    s_ret[idx] = '\0';
    i = t_len - 1;
    idx = 0;
    del = 0;
    while(i >= 0){
        if(t[i] == '#'){
            del++;
        }
        else if(del > 0){
            del--;
        }
        else{
            t_ret[idx++] = t[i];
        }
        i--;
    }
    t_ret[idx] = '\0';
    if(strlen(s_ret) != strlen(t_ret)) return false;
    else
        for(i = 0; i < strlen(s_ret); i++){
            if(s_ret[i] != t_ret[i]) return false;
        }
    
    return true;
}