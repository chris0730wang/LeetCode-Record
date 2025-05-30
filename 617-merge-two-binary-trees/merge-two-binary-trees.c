/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    struct TreeNode* newNode = NULL;
    if(root1 || root2){
        newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        int val1 = root1 ? root1->val : 0;
        int val2 = root2 ? root2->val : 0;
        newNode->val = val1 + val2;
        newNode->left = mergeTrees(root1 ? root1->left : NULL, root2 ? root2->left : NULL);
        newNode->right = mergeTrees(root1 ? root1->right : NULL, root2 ? root2->right : NULL);
    }
    return newNode;
}