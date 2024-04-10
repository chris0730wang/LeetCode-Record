/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */ 
int rangeSumBST(struct TreeNode* root, int low, int high) {
    int ret = 0;
    if(!root) return 0;
    if(root->val >= low && root->val <= high) ret += root->val;
    if(root->left) ret += rangeSumBST(root->left, low, high);
    if(root->right) ret += rangeSumBST(root->right, low, high);
    return ret;
}