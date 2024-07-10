/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(!root) return false;
    targetSum -= root->val;
    if(targetSum == 0 && !root->left && !root->right) return true;
    else{
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
}