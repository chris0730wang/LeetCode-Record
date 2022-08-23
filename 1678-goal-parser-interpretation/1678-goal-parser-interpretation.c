

char * interpret(char * command){
    int len = strlen(command) + 1;
    char *res = (char*)malloc(sizeof(char) * 101);
    int index = 0;
    for(int i=0; i<len; i++){
        if(command[i] == '('){
            int j = i;
            while(command[j] != ')') j++;
            if(j - i == 1) res[index++] = 'o';
            if(j - i == 3) {
                res[index++] = 'a';
                res[index++] = 'l';
            }
            i = j;
        }else{
            res[index++] = command[i];
        }
    }
    res[index] = '\0';
    return res;
}