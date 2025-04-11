/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void order(struct TreeNode* root, int* ret, int* returnSize){
    if(!root) return;
    ret[(*returnSize)++] = root->val;
    order(root->left, ret, returnSize);
    order(root->right, ret, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* ret = (int*)malloc(sizeof(int) * 100);
    order(root, ret, returnSize);
    return ret;
}