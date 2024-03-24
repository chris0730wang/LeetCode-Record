int countNegatives(int** grid, int gridSize, int* gridColSize) {
    int ret = 0;
    for(int i = 0; i < gridSize; i++){
        if(grid[i][(*gridColSize) - 1] > 0) continue;
        for(int j = 0; j < (*gridColSize); j++){
            if(grid[i][j] < 0) {
                ret += (*gridColSize) - j;
                break;
            }
        }
    }
    return ret;
}
