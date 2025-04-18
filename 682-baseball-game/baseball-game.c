int calPoints(char** operations, int operationsSize) {
    int* stack = (int*)malloc(sizeof(int) * operationsSize);
    int top = -1;
    int res = 0;
    
    for(int i = 0; i < operationsSize; i++){
        if(operations[i][0] == 'C'){
            res -= stack[top];
            top--;
        }
        else if(operations[i][0] == 'D'){
            stack[++top] = stack[top] * 2;
            res += stack[top];
        }
        else if(operations[i][0] == '+'){
            stack[++top] = stack[top] + stack[top-1];
            res += stack[top];
        }
        else{
            bool minus = false;
            int len = strlen(operations[i]);
            int score = 0;
            for(int j = 0; j < len; j++){
                if(operations[i][j] == '-'){
                    minus = true;
                    continue;
                }
                score = score * 10 + (operations[i][j] - '0');
            }
            stack[++top] = minus ? 0-score : score;
            res += stack[top];
        }
    }
    return res;
}