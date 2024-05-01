/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* currNode = head;
    struct ListNode* tmpNode = NULL;
    while(currNode){
        struct ListNode* nextNode = currNode->next;
        currNode->next = tmpNode;
        tmpNode = currNode;
        currNode = nextNode;
    }
    return tmpNode;
}