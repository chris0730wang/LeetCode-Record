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
            bool neg = operations[i][0] == '-';
            int start = neg ? 1 : 0;
            int len = strlen(operations[i]);
            int score = 0;
            for(int j = start; j < len; j++){
                score = score * 10 + (operations[i][j] - '0');
            }
            stack[++top] = neg ? 0-score : score;
            res += stack[top];
        }
    }

    free(stack);
    return res;
}