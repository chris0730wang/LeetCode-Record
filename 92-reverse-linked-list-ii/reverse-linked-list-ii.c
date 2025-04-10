/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* head){
    struct ListNode* tmpNode = NULL;
    struct ListNode* nextNode = NULL;
    while(head){
        nextNode = head->next;
        head->next = tmpNode;
        tmpNode = head;
        head = nextNode;
    }
    return tmpNode;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    int past = left - 1, last = right + 1;
    struct ListNode* tmpNode = head;
    struct ListNode* pastNode = NULL;
    struct ListNode* nextNode = NULL;
    struct ListNode* leftNode = NULL;
    for(int i = 1; i <= right; i++){
        if(i == past) pastNode = tmpNode;
        else if(i == left) leftNode = tmpNode;
        if(i == right) {
            nextNode = tmpNode->next;
            tmpNode->next = NULL;
        }
        tmpNode = tmpNode->next;
    }
    if(past == 0) {
        head = reverse(head);
        tmpNode = head;
    }
    else {
        pastNode->next = reverse(leftNode);
        tmpNode = pastNode;
    }
    while(tmpNode->next){
        tmpNode = tmpNode->next;
    }
    tmpNode->next = nextNode;
    return head;
}