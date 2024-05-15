#define MAX_ROW 100
#define MAX_COL 100

bool dfs(char **board, int boardSize, int boardColSize, int row, int col, int index, char *word) {
    if (index == strlen(word)) {
        return true;
    }
    if (row < 0 || col < 0 || row >= boardSize || col >= boardColSize || board[row][col] != word[index]) {
        return false;
    }

    char original = board[row][col];
    board[row][col] = '\0';

    bool found = dfs(board, boardSize, boardColSize, row + 1, col, index + 1, word) ||
                 dfs(board, boardSize, boardColSize, row - 1, col, index + 1, word) ||
                 dfs(board, boardSize, boardColSize, row, col + 1, index + 1, word) ||
                 dfs(board, boardSize, boardColSize, row, col - 1, index + 1, word);

    board[row][col] = original;

    return found;
}

bool exist(char **board, int boardSize, int *boardColSize, char *word) {
    int row = boardSize;
    int col = *boardColSize;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (dfs(board, boardSize, boardColSize[i], i, j, 0, word)) {
                return true;
            }
        }
    }

    return false;
}