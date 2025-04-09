int cmp(const void *a, const void *b){
    return *(int*)b - *(int*)a;
}

int hIndex(int* citations, int citationsSize) {
    int res = 0;
    qsort(citations, citationsSize, sizeof(int), cmp);
    for(int i = 0; i < citationsSize; i++){
		if(citations[i] > res) res++;
        else break;
	}
	return res;
}