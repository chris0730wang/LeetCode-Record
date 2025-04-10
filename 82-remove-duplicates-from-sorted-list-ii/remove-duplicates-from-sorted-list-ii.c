/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;
    dummy.val = -101;
    struct ListNode* res = &dummy;
    struct ListNode* tmpNode = res;
    struct ListNode* chkNode = tmpNode->next;
    struct ListNode* node;
    struct ListNode* lastNode;
    while(tmpNode && tmpNode->next){
        node = tmpNode->next;
        if(node->val == tmpNode->val){
            node = tmpNode;
            tmpNode = lastNode;
        }
        chkNode = node->next;
        if(!chkNode) {
            tmpNode->next = node;
        }
        else if(chkNode->val == node->val){
            while(chkNode && chkNode->val == node->val) chkNode = chkNode->next;
            tmpNode->next = chkNode;
        }
        lastNode = tmpNode;
        tmpNode = tmpNode->next;
    }
    return res->next;
}