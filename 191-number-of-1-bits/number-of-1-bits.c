int hammingWeight(int n) {
    int tmp = 2;
    // int times = 1;
    int ret = 0;
    while(n > 0){
        if(n % 2 == 1) ret++;
        n /= 2;
    }
    
    return ret;
}

