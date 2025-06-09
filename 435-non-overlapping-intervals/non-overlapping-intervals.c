int cmp(const void *a, const void *b){
    int* intA = *(int**)a;
    int* intB = *(int**)b;
    return intA[0] - intB[0];
}
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int lastStart = intervals[0][0];
    int lastEnd = intervals[0][1];
    int res = 0;
    for(int i = 1; i < intervalsSize; i++){
        if(intervals[i][0] >= lastEnd){
            lastStart = intervals[i][0];
            lastEnd = intervals[i][1];
        }
        else if(intervals[i][0] == lastStart){
            res++;
            lastEnd = intervals[i][1] < lastEnd ? intervals[i][1] : lastEnd;
        }
        else if(intervals[i][0] > lastStart){
            res++;
            lastStart = intervals[i][1] < lastEnd ? intervals[i][0] : lastStart;
            lastEnd = intervals[i][1] < lastEnd ? intervals[i][1] : lastEnd;
        }
    }
    return res;
}