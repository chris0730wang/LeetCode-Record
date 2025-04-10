/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;
    struct ListNode* dummy2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tmpNode = dummy2;
    dummy2->next = NULL;
    while(curr){
        if(curr->val >= x){
            tmpNode->next = curr;
            curr = curr->next;
            tmpNode = tmpNode->next;
            tmpNode->next = NULL;
        }
        else{
            prev->next = curr;
            curr = curr->next;
            prev = prev->next;
            prev->next = NULL;
        }
        
    }
    prev->next = dummy2->next;
    return dummy.next;
}