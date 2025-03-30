/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* ret = NULL;
    dummy->next = NULL;
    int add = 0;
    int sum;
    while(l1 && l2){
        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        sum = l1->val + l2->val + add;
        newNode->val = sum % 10;
        add = sum / 10;
        if(!dummy->next) {
            dummy->next = newNode;
            ret = newNode;
        }
        else {
            ret->next = newNode;
            ret = ret->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1){
        sum = l1->val + add;
        l1->val = sum % 10; 
        add = sum / 10;
        ret->next = l1;
        l1 = l1->next;
        ret = ret->next;
    }
    while(l2){
        sum = l2->val + add;
        l2->val = sum % 10; 
        add = sum / 10;
        ret->next = l2;
        l2 = l2->next;
        ret = ret->next;
    }
    if(add == 1){
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        newNode->val = 1;
        ret->next = newNode;
    }
    return dummy->next;
}