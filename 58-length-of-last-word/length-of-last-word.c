int lengthOfLastWord(char* s) {
    int res = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == ' ')continue;
        if(i > 0 && s[i - 1] == ' '){
            res = 0;
        }
        res++;
    }
    return res;
}