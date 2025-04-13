/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void reCount(struct TreeNode* root, int* curr){
    if(!root) return;
    reCount(root->right, curr);
    *curr += root->val;
    root->val = *curr;
    reCount(root->left, curr);
    return;
}

struct TreeNode* bstToGst(struct TreeNode* root) {
    int curr = 0;
    reCount(root, &curr);
    return root;
}