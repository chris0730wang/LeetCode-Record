int candy(int* ratings, int ratingsSize) {
    if(ratingsSize == 1) return 1;
    int gap = 0, gap_num = 0;
    int ret = 0;
    int *tmp = (int*)malloc(sizeof(int) * ratingsSize);
    for(int i = 0; i < ratingsSize; i++) tmp[i] = 1;
    for(int i = 0; i < ratingsSize - 1; i++){
        if(ratings[i + 1] > ratings[i]) tmp[i + 1] = tmp[i] + 1;
    }

    for(int i = ratingsSize - 1; i > 0; i--){
        if(ratings[i - 1] > ratings[i]) tmp[i - 1] = tmp[i - 1] > tmp[i] + 1 ? tmp[i - 1] : tmp[i] + 1;
    }

    for(int i = 0; i < ratingsSize; i++) ret += tmp[i];
    return ret;
}