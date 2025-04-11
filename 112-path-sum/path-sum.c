/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool check(struct TreeNode* root, int sum, int target) {
    if (!root) return false;

    sum += root->val;

    if (!root->left && !root->right) {
        return sum == target;
    }

    return check(root->left, sum, target) || check(root->right, sum, target);
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    return check(root, 0, targetSum);
}