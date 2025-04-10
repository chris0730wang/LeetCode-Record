/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool checkNode(struct TreeNode* node1, struct TreeNode* node2){
    if(!node1 && !node2) return true;
    if(!node1 || !node2) return false;
    return node1->val == node2->val && checkNode(node1->right, node2->left) && checkNode(node1->left, node2->right);
} 
bool isSymmetric(struct TreeNode* root) {
    return checkNode(root->left, root->right);
}