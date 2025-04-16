int largestAltitude(int* gain, int gainSize) {
    int res = INT_MIN, tmp = 0;
    for(int i = 0; i < gainSize; i++){
        tmp += gain[i];
        res = tmp > res ? tmp : res;
    }
    return res < 0 ? 0 : res;
}