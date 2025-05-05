/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(!list1) return list2;
    if(!list2) return list1;
    struct ListNode* currNode = NULL;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(list1->val < list2->val){
        currNode = list1;
        list1 = list1->next;
    }
    else{
        currNode = list2;
        list2 = list2->next;
    }
    dummy->next = currNode;
    while(list1 && list2){
        if(list1->val < list2->val){
            currNode->next = list1;
            list1 = list1->next;
        }
        else{
            currNode->next = list2;
            list2 = list2->next;
        }
        currNode = currNode->next;
    }
    if(list1) currNode->next = list1;
    else currNode->next = list2;

    return dummy->next;
}