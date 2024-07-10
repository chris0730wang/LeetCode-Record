/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(preorderSize == 0 || inorderSize == 0) return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;

    int index = 0;
    for(index = 0; index < inorderSize; index++){
        if(inorder[index] == preorder[0]){
            break;
        }
    }

    root->left = buildTree(preorder + 1, index, inorder, index);
    root->right = buildTree(preorder + 1 + index, preorderSize - 1 - index, inorder + index + 1, inorderSize - 1 - index);

    return root;
}