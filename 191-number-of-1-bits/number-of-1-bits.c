int hammingWeight(int n) {
    int tmp = 2;
    // int times = 1;
    int ret = 0;
    while(n > 1){
        while(1){
            if(tmp == 1073741824 || tmp * 2 > n) break;
            tmp *= 2;
        }
        n -= tmp;
        tmp = 2;
        ret++;
    }
    ret += n;
    return ret;
}

