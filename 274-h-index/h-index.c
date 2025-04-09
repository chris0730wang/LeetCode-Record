int hIndex(int* citations, int citationsSize) {
    for(int i = citationsSize; i > 0; i--){
		int times = 0;
		for(int j = 0; j < citationsSize; j++){
			if(citations[j] >= i) times++;
			if(times == i) return i;
		}
	}
	return 0;
}