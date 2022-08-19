/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    struct ListNode* index = head;
    int len = 0;
    while(index != NULL){
        len++;
        index = index->next;
    }
    index = head;
    for(int i=0; i<(len/2); i++) index = index->next;
    return index;
}