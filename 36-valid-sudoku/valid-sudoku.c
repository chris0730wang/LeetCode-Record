bool check(char** board, int row, int col){
    int *tmp = (int*)calloc(9, sizeof(int));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[row + i][col + j] == '.') continue;
            if(tmp[board[row + i][col + j] - '1'] > 0) return false;
            tmp[board[row + i][col + j] - '1']++;
        }
    }
    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    for(int i = 0; i < 9; i++){
        int *tmp = (int*)calloc(9, sizeof(int));
        for(int j = 0; j < 9; j++){
            if(board[i][j] == '.') continue;
            if(tmp[board[i][j] - '1'] > 0) return false;
            tmp[board[i][j] - '1']++;
        }
    }
    for(int i = 0; i < 9; i++){
        int *tmp = (int*)calloc(9, sizeof(int));
        for(int j = 0; j < 9; j++){
            if(board[j][i] == '.') continue;
            if(tmp[board[j][i] - '1'] > 0) return false;
            tmp[board[j][i] - '1']++;
        }
    }
    for(int i = 0; i < 9; i += 3){
        for(int j = 0; j < 9; j += 3){
            if(check(board, i, j) == false) return false;
        }
    }
    return true;
}