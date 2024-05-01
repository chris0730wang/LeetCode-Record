/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    int tmp = 1;
    int num = 1;
    struct ListNode* tmpNode = head->next;
    struct ListNode* retNode = head;
    while(tmpNode){
        num++;
        tmpNode = tmpNode->next;
        if(num / 2 >= tmp) {
            retNode = retNode->next;
            tmp++;
        }
    }
    return retNode;
}