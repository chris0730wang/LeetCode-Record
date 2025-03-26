int maxProfit(int* prices, int pricesSize) {
    int min = prices[0];
    int res = 0;
    for(int i = 1; i < pricesSize; i++){
        res = prices[i] - min > res ? prices[i] - min : res;
        min = prices[i] < min ? prices[i] : min;
    }
    return res;
}