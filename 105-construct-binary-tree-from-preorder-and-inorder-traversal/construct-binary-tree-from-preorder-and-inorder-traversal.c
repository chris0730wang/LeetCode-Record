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
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = preorder[0];
    int i = 0;
    while(i < inorderSize && inorder[i] != newNode->val){
        i++;
    }
    newNode->left = buildTree(preorder + 1, i, inorder, i);
    newNode->right = buildTree(preorder + 1 + i, preorderSize - i - 1, inorder + i + 1, preorderSize - i - 1);
    return newNode;
}