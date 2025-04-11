/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool check(struct TreeNode* root, int targetSum, int* sum){
    if(!root) return false;
    
    *sum += root->val;

    if(root->left == NULL && root->right == NULL){
        if(*sum == targetSum) return true;
    }

    if(check(root->left, targetSum, sum) || check(root->right, targetSum, sum)) return true;

    *sum -= root->val;
    return false;
} 

bool hasPathSum(struct TreeNode* root, int targetSum) {
    int sum = 0;
    return check(root, targetSum, &sum);
}