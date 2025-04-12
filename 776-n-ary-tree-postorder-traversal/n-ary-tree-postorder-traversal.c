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
    for(int i = 0; i < root->numChildren; i++){
        order(root->children[i], returnSize, res);
    }
    res[(*returnSize)++] = root->val;
}

int countNodes(struct Node* root){
    if (!root) return 0;
    int count = 1; // 自己
    for (int i = 0; i < root->numChildren; i++) {
        count += countNodes(root->children[i]);
    }
    return count;
}

int* postorder(struct Node* root, int* returnSize) {
    int count = countNodes(root);
    int* res = (int*)malloc(sizeof(int) * count);
    *returnSize = 0;
    order(root, returnSize, res);
    return res;
}