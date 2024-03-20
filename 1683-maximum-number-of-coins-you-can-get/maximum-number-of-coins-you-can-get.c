int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int maxCoins(int* piles, int pilesSize) {
    int ret = 0;
    qsort(piles, pilesSize, sizeof(int), cmp);
    for(int i = pilesSize - 2, n = 0; i > n; i-=2){
        ret += piles[i];
        n++;
    }
    return ret;
}