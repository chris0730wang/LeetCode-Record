/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
	if (!root) return NULL;

    struct Node* curr = root;
    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    dummy->next = NULL;

    while (curr) {
        struct Node* tail = dummy;
        dummy->next = NULL;

        while (curr) {
            if (curr->left) {
                tail->next = curr->left;
                tail = tail->next;
            }
            if (curr->right) {
                tail->next = curr->right;
                tail = tail->next;
            }
            curr = curr->next;
        }
        curr = dummy->next;
    }

    free(dummy);
    return root;
}