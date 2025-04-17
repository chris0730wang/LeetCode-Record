char* decodeString(char* s) {
    char* strStack[1000];   // 保存字串部分
    int  numStack[1000];    // 保存重複次數
    int  top = -1;          // stack top

    int len = strlen(s);
    char* currStr = (char*)calloc(2000, sizeof(char));
    int  currNum = 0;

    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            currNum = currNum * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            // 將當前字串與數字推入 stack
            numStack[++top] = currNum;
            strStack[top] = currStr;
            currStr = (char*)calloc(2000, sizeof(char));
            currNum = 0;
        } else if (s[i] == ']') {
            // 出 stack 並重複合併
            int repeat = numStack[top];
            char* prevStr = strStack[top--];

            int prevLen = strlen(prevStr);
            for (int j = 0; j < repeat; j++) {
                strcat(prevStr, currStr);
            }

            free(currStr);
            currStr = prevStr;
        } else {
            // 加到目前字串
            int l = strlen(currStr);
            currStr[l] = s[i];
            currStr[l + 1] = '\0';
        }
    }

    return currStr;
}