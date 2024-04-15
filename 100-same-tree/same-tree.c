/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p && q){
        if(p->val != q->val) return false;
        if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) return true;
        return false;
    }
    else if((p && !q) || (!p && q)){
        return false;
    }
    return true;
}