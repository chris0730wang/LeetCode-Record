/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(!root) return 0;
	int l_depth = maxDepth(root->left);
	int r_depth = maxDepth(root->right);
	return l_depth > r_depth ? l_depth + 1 : r_depth + 1;
}
