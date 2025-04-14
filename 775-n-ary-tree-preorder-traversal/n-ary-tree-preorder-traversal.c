/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void order(struct Node* root, int* returnSize, int* res){
    if(!root) return;
    res[(*returnSize)++] = root->val;
    for(int i = 0; i < root->numChildren; i++){
        order(root->children[i], returnSize, res);
    }
}

int* preorder(struct Node* root, int* returnSize) {
    *returnSize = 0;
    int* res = (int*)malloc(sizeof(int) * 10000);
    order(root, returnSize, res);
    return res;
}