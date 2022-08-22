bool isValid(char * s){
    char stack[10000]= { 0 };
    int top = 0;
    while(*s) {
        if(*s == '(')// ASCII code中")"是"("加一。
            stack[top++] = *s + 1;
        else if(*s == '[' || *s == '{')// ASCII code中"}"是"{"加一。 []也是
            stack[top++] = *s + 2;
        else if(top == 0)
            return false;
        else if(stack[top - 1] == *s)
            top--;
        else
            return false;
        s++;
    }
    if(top == 0) return true;
    else return false;
}