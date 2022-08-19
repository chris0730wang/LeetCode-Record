/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *temp, *q=NULL;
    temp = node;
    while(temp->next != NULL){
        q=temp;
        temp->val = temp->next->val;
        temp = temp->next;
    }
    q->next = NULL;
}
