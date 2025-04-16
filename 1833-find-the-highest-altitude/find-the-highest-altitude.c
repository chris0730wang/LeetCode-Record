int largestAltitude(int* gain, int gainSize) {
    int res = 0, tmp = 0;
    for(int i = 0; i < gainSize; i++){
        tmp += gain[i];
        res = tmp > res ? tmp : res;
    }
    return res;
}