/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    struct ListNode *temp = NULL, *neck = head;
    while(head->next!=NULL){
        temp = head->next;
        head->next = head->next->next;
        temp->next = neck;
        neck = temp;
    }
    return neck;
}