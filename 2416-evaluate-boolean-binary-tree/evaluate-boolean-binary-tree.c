/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool evaluateTree(struct TreeNode* root) {
    
	if(root->val == 0){
		return false;
	}
	else if (root->val == 1){
		return true;
	}
	else if (root->val == 2){
		return evaluateTree(root->left) == true || evaluateTree(root->right) == true;
	}
	else{
		return evaluateTree(root->left) == true && evaluateTree(root->right) == true;
	}
}