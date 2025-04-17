char* removeStars(char* s) {
    int index = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        if(s[i] == '*'){
            index--;
        }
        else{
            s[index++] = s[i];
        }
    }
    s[index] = '\0';
    return s;
}