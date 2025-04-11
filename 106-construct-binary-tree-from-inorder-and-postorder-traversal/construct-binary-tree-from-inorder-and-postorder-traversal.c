/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if(postorderSize == 0 || inorderSize == 0) return NULL;
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = postorder[postorderSize - 1];
    int i = 0;
    while(i < inorderSize && inorder[i] != newNode->val){
        i++;
    }
    
    newNode->left = buildTree(inorder, i, postorder, i);
    newNode->right = buildTree(inorder + i + 1, inorderSize - i - 1, postorder + i, postorderSize - i - 1);

    return newNode;
}