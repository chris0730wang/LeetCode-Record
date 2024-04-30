/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int low = p->val < q->val ? p->val : q->val;
    int high = p->val > q->val ? p->val : q->val;
    if(root->val > low && root->val < high) return root;
    else if(root->val > high) return lowestCommonAncestor(root->left, p, q);
    else if(root->val < low) return lowestCommonAncestor(root->right, p, q);
    else if(root->val == low || root->val == high) return root; 
    return root;
}