

int balancedStringSplit(char * s){
    int res = 0, sum = 0;
    int len = strlen(s);
    while(*s){
        if(*s++ == 'R')sum++;
        else sum--;
        if(sum == 0) res++;
    }
    return res;
}