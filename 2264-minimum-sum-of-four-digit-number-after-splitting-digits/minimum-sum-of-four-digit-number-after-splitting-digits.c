int minimumSum(int num) {
    int *tmp = (int*)malloc(sizeof(int) * 4);
    tmp[0] = num / 1000;
    tmp[1] = (num % 1000) / 100;
    tmp[2] = (num % 100) / 10;
    tmp[3] = num % 10;
    for(int i = 1; i < 4; i++){
        int n = tmp[i];
        int j = i - 1;
        while(j >= 0 && n < tmp[j]){
            tmp[j + 1] = tmp[j];
            j--;
        }
        tmp[j + 1] = n;
    }
    return tmp[0] * 10 + tmp[1] * 10 + tmp[2] + tmp[3];
}