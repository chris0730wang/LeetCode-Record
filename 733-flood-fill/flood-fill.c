/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(int **image, int imageSize, int imageColSize, int sr, int sc, int oldColor, int newColor) {
    if (sr < 0 || sr >= imageSize || sc < 0 || sc >= imageColSize || image[sr][sc] != oldColor || image[sr][sc] == newColor) {
        return;
    }
    
    image[sr][sc] = newColor;
    
    dfs(image, imageSize, imageColSize, sr + 1, sc, oldColor, newColor);
    dfs(image, imageSize, imageColSize, sr - 1, sc, oldColor, newColor);
    dfs(image, imageSize, imageColSize, sr, sc + 1, oldColor, newColor);
    dfs(image, imageSize, imageColSize, sr, sc - 1, oldColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    if (image == NULL || imageSize == 0 || imageColSize == NULL || *imageColSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    int oldColor = image[sr][sc];
    
    if (oldColor == color) {
        *returnSize = imageSize;
        *returnColumnSizes = imageColSize;
        return image;
    }
    
    dfs(image, imageSize, *imageColSize, sr, sc, oldColor, color);
    
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    
    return image;
}