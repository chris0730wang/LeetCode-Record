char* convert(char* s, int numRows) {
    if(numRows == 1) return s;
    int step = numRows - 1 + numRows - 1;
    int gap = 0;
    int len = strlen(s);
    int index = 0;
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    res[0] = '\0';
    for(int i = 0; i < numRows; i++){
        bool flag = true;
        int j = i;
        while(j < len){
            res[index] = s[j];
            if(flag){
                j += gap == step ? gap : step - gap;
                flag = false;
            }
            else{
                j += gap == 0 ? step - gap : gap;
                flag = true;
            }
            index++;
        }
        gap += 2;
    }
    res[index] = '\0';
    return res;
}

// P       H
// A     S I
// Y   I   R
// P L     I G
// A       N


// 4  => 6 4,2 2,4 6
// 5  => 8 6,2 4,4 2,6 8