/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(!head || !head->next) return head;
    struct ListNode* prev = (struct ListNode*)malloc(sizeof(struct ListNode));
    prev->next = head;
    struct ListNode* first = head;
    struct ListNode* second = head->next;
    struct ListNode* ret = second;
    while(second){
        struct ListNode* tmpNode = first;
        prev->next = second;
        first->next = second->next;
        second->next = first;
        prev = first;
        first = first->next;
        second = first ? first->next : NULL;
    }
    return ret;
}