void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int** temp = (int**)malloc(sizeof(int*) * (matrixSize));
    for(int i = 0; i < matrixSize; i++){
        temp[i] = (int*)malloc(sizeof(int) * matrixSize);
        //matrixColSize[i] = matrixSize;
    }
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++){
            temp[j][matrixSize-i-1] = matrix[i][j];
        }
    }
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++){
            matrix[i][j] = temp[i][j];
        }
    }
    return;
}