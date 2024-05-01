// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int left = 1, right = n;
    int tmp;
    while(left < right){
        tmp = left + ((right - left) / 2);
        if(isBadVersion(tmp)) return firstBadVersion(tmp);
        else left = tmp + 1;
    }
    return n;
}
