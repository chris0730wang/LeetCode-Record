int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    qsort(piles, pilesSize, sizeof(int), cmp);
    int left = 1, right = piles[pilesSize-1];
    while(left <= right){
        long long mid = (left + right) / 2;
        long long hours = 0;
        for(int i = 0; i < pilesSize; i++){
            hours += (piles[i] + mid - 1) / mid;
        }
        if(hours > h) left = mid + 1;
        else if(hours <= h) right = mid - 1;
    }
    return (int)left;
}