int scoreOfParentheses(char* s) {
    int stack[30];
    int top = -1;
    stack[++top] = 0;  // 初始值為 0

    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            stack[++top] = 0;  // 新一層括號，先放 0
        } else {
            int inner = stack[top--];  // 這層的值
            int outer = stack[top--];  // 外層的值
            int score = inner == 0 ? 1 : 2 * inner;
            stack[++top] = outer + score;
        }
    }

    return stack[top];
}