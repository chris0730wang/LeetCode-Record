int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    int ret = 0;
    qsort(arr2, arr2Size, sizeof(int), cmp);
    for(int i = 0; i < arr1Size; i++){
        int l = 0, r = arr2Size - 1;
        bool flag = false;
        int tmp = arr2[(l + r) / 2];
        while(l < r){
            tmp = arr2[(l + r) / 2];
            flag = arr1[i] < tmp ? true : false;
            int sum = abs(arr1[i] - tmp);
            if(sum <= d) break;
            else{
                l = flag ? l : (l + r) / 2 + 1;
                r = flag ? (l + r) / 2 - 1 : r;
            }
        }
        if(abs(arr1[i] - arr2[(l + r) / 2]) > d) ret++;
    }
    return ret;
}