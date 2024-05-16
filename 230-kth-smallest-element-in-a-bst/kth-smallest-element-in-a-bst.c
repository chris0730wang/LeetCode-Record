/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// 中序遍历函数
void inorder(struct TreeNode *root, int k, int *count, int *result) {
    if (root == NULL) return;
    inorder(root->left, k, count, result);
    (*count)++;
    if (*count == k) {
        *result = root->val;
        return;
    }
    inorder(root->right, k, count, result);
}

// 寻找二叉搜索树中第K小的元素
int kthSmallest(struct TreeNode* root, int k) {
    int count = 0;
    int result = 0;
    inorder(root, k, &count, &result);
    return result;
}