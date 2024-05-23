/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(!head || !head->next) return head;
    struct ListNode *tmpNode = head;
    struct ListNode *odd = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *conn = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *even = conn;
    while(tmpNode){
        odd->next = tmpNode;
        even->next = tmpNode->next;
        tmpNode = tmpNode->next ? tmpNode->next->next : NULL;
        odd = odd->next;
        even = even->next;       
    }
    odd->next = conn->next;
    return head;
}