char* convert(char* s, int numRows) {
    if(numRows == 1) return s;
    int x = (numRows - 1) * 2;
    int y = 0;
    int len = strlen(s);
    char* ret = (char*)malloc(sizeof(char) * (len + 1));
    ret[len] = '\0';
    int index = 0;
    for(int i = 0; i < numRows; i++){
        int j = i;
        while(j < len){
            if(x != 0)ret[index++] = s[j];
            j += x;
            if(i != 0 && j < len)ret[index++] = s[j];
            j += 2 * i;
        }
        x -= 2;
    }
    return ret;
}

