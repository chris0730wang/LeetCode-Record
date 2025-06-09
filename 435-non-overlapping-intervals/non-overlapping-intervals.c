int cmp(const void *a, const void *b){
    int* intA = *(int**)a;
    int* intB = *(int**)b;
    return intA[1] - intB[1];
}
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int lastEnd = intervals[0][1];
    int res = 0;
    for(int i = 1; i < intervalsSize; i++){
        if(intervals[i][0] >= lastEnd){
            lastEnd = intervals[i][1];
        }
        else{
            res++;
        }
    }
    return res;
}