int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    int **dp = (int**)malloc(sizeof(int*) * matrixSize);
	int ret = 0;
	for(int i = 0; i < matrixSize; i++){
		dp[i] = (int*)calloc(matrixColSize[i], sizeof(int));
	}
	for(int i = matrixSize - 1; i >= 0; i--){
		for(int j = matrixColSize[i] - 1; j >= 0; j--){
			if(matrix[i][j] == '0') continue;
			if(i == matrixSize - 1 || j == matrixColSize[i] - 1){
				dp[i][j] = 1;
			}
			else{
				dp[i][j] = dp[i + 1][j] < dp[i][j + 1] ? dp[i + 1][j] : dp[i][j + 1];
				dp[i][j] = dp[i + 1][j + 1] < dp[i][j] ? 1 + dp[i + 1][j + 1] : 1 + dp[i][j];
			}
			ret = dp[i][j] > ret ? dp[i][j] : ret;
		}
	}
	return ret * ret;
}