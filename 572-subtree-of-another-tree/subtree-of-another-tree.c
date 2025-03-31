/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameNode(struct TreeNode* root1, struct TreeNode* root2){
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    if(root1->val != root2->val) return false;

    return isSameNode(root1->left, root2->left) && isSameNode(root1->right, root2->right);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (!root) return false; 
    if (isSameNode(root, subRoot)) return true; 

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}