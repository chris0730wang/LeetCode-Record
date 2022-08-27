

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int max = 0, sum = 0, temp = 0;
    for(int i=0; i<accountsSize; i++){
        for(int j=0; j<(*accountsColSize); j++){
            temp += accounts[i][j];
        }
        if(temp > max) max = temp;
        temp = 0;
    }
    return max;
}