/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* tmpNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    tmpNode = head;
    int cnt = 0;
    while(tmpNode){
        cnt++;
        tmpNode = tmpNode->next;
    }
    if(cnt == n) return head->next;
    tmpNode = head;
    struct ListNode* nextNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    nextNode = tmpNode->next;
    while(nextNode){
        cnt--;
        if(cnt == n){
            tmpNode->next = nextNode->next;
            break;
        }
        tmpNode = nextNode;
        nextNode = nextNode->next;
    }
    return head;
}