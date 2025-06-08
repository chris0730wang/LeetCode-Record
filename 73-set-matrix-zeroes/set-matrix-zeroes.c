void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    bool** chk = (bool**)malloc(sizeof(bool*) * matrixSize);
    for(int i = 0; i < matrixSize; i++){
        chk[i] = (bool*)malloc(sizeof(bool) * matrixColSize[0]);
        for(int j = 0; j < matrixColSize[0]; j++){
            if(matrix[i][j] == 0) chk[i][j] = true;
            else chk[i][j] = false;
        }
    }
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixColSize[0]; j++){
            if(chk[i][j] == true){
                for(int k = 0; k < matrixSize; k++) matrix[k][j] = 0;
                for(int k = 0; k < matrixColSize[0]; k++) matrix[i][k] = 0;
            }
        }
    }
    return;
}