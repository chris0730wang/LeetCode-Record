/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void sum(struct TreeNode* root, int low, int high, int* res){
    if(!root) return;

    if(root->val >= low && root->val <= high) *res += root->val;
    sum(root->right, low, high, res);
    sum(root->left, low, high, res);
}

int rangeSumBST(struct TreeNode* root, int low, int high) {
    int* res = (int*)malloc(sizeof(int));
    *res = 0;
    sum(root, low, high, res);
    return *res;
}