/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

int maxDepth(struct Node* root) {
    int ret = 0;
    if(!root) ret = 0;
    else if(root->numChildren == 0) ret = 1;
    else {
        int max = 0;
        for(int i = 0; i < root->numChildren; i++){
            int tmp = maxDepth(root->children[i]);
            max = tmp > max ? tmp : max;
        }
        ret = max + 1;
    }
    return ret;
}