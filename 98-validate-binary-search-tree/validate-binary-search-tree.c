/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 輔助函式：使用範圍（區間）來驗證 BST
bool isValidBSTHelper(struct TreeNode* node, long minVal, long maxVal) {
    if (node == NULL) return true; // 空樹視為有效 BST

    // 節點值必須在 (minVal, maxVal) 區間內
    if (node->val <= minVal || node->val >= maxVal) return false;

    // 遞迴檢查左子樹（上界變為當前節點值），右子樹（下界變為當前節點值）
    return isValidBSTHelper(node->left, minVal, node->val) &&
           isValidBSTHelper(node->right, node->val, maxVal);
}

bool isValidBST(struct TreeNode* root) {
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);   
}