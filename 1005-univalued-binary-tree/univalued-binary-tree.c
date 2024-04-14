/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isUnivalTree(struct TreeNode* root) {
    bool ret = true;
    if(!root) return true;
    if(root->left) {
        if(isUnivalTree(root->left) == false) return false;
        ret = root->val == root->left->val ? ret : false;
    }
    if(root->right) {
        if(isUnivalTree(root->right) == false) return false;
        ret = root->val == root->right->val ? ret : false;
    }
    return ret;
}