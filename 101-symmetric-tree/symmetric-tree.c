/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSame(struct TreeNode* root1, struct TreeNode* root2){
    if((root1 && !root2) || (!root1 && root2)) return false;
    if(!root1 && !root2) return true;
    return root1->val == root2->val && isSame(root1->left, root2->right) && isSame(root1->right, root2->left);
}
bool isSymmetric(struct TreeNode* root) {
    if(!root) return true;
    return isSame(root->left, root->right);
}