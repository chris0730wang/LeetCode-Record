/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(!head || !head->next) return false;
    struct ListNode* tmpNode1 = head->next;
    struct ListNode* tmpNode2 = head->next->next;
    while(tmpNode1 && tmpNode2){
        if(tmpNode1 == tmpNode2) return true;
        if(!tmpNode2->next) return false;
        tmpNode1 = tmpNode1->next;
        tmpNode2 = tmpNode2->next->next; 
    }
    return false;
}