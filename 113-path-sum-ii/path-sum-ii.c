/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_PATH_LEN 1000

void dfs(struct TreeNode* root, int targetSum, int* path, int pathLen,
         int*** res, int* returnSize, int** returnColumnSizes, int sum) {
    if (!root) return;

    path[pathLen++] = root->val;
    sum += root->val;

    if (!root->left && !root->right && sum == targetSum) {
        (*returnSize)++;
        *res = realloc(*res, sizeof(int*) * (*returnSize));
        (*res)[*returnSize - 1] = malloc(sizeof(int) * pathLen);
        memcpy((*res)[*returnSize - 1], path, sizeof(int) * pathLen);

        *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (*returnSize));
        (*returnColumnSizes)[*returnSize - 1] = pathLen;
    }

    dfs(root->left, targetSum, path, pathLen, res, returnSize, returnColumnSizes, sum);
    dfs(root->right, targetSum, path, pathLen, res, returnSize, returnColumnSizes, sum);
}


int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    int** res = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    int* path = malloc(sizeof(int) * MAX_PATH_LEN);

    dfs(root, targetSum, path, 0, &res, returnSize, returnColumnSizes, 0);

    free(path);
    return res;
}