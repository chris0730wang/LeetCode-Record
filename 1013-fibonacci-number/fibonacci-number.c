

int fib(int n){
    if(n < 2) return n;
    int *ret = (int*)malloc(sizeof(int) * 3);
    ret[0] = 0;
    ret[1] = 1;
    for(int i = 1; i < n; i++){
        ret[2] = ret[0] + ret[1];
        ret[0] = ret[1];
        ret[1] = ret[2];
    }
    return ret[2];
}