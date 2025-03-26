int maxProfit(int* prices, int pricesSize) {
    int l = 0, r = 1;
    int res = 0;

    while (r < pricesSize) {
        if(prices[l] < prices[r]){
            int val = prices[r] - prices[l];
            res = val > res ? val : res;
        }
        else{
            l = r;
        }
        r++;
    }
    return res;
}