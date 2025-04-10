/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(k == 0 || !head) return head;
    int len = 0;
    struct ListNode* tmpNode = head;
    struct ListNode* lastNode;
    struct ListNode* newhead;
    while(tmpNode){
        len++;
        lastNode = tmpNode;
        tmpNode = tmpNode->next;
    }
    if(len == 1 || k % len == 0) return head;
    k = k % len;
    tmpNode = head;
    for(int i = 0; i < len - k - 1; i++){
        tmpNode = tmpNode->next;
    }
    newhead = tmpNode->next;
    tmpNode->next = NULL;
    lastNode->next = head;
    return newhead;
}