/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int listlen(struct ListNode* head){
    int len = 0;
    while(head != NULL){
        head = head->next;
        len++;
    }
    return len;
}

struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    struct ListNode *prev = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return prev;
}

int pairSum(struct ListNode* head){
    struct ListNode *first_part = head, *second_part = head;
    int len = listlen(head);
    if(len == 2)return head->val + head->next->val;
    for(int i=0; i<len/2; i++){
        second_part = second_part->next;
    }
    struct ListNode *rev_second_part = reverseList(second_part);
    int max = 0, temp = 0;
    for(int i=0; i<len/2; i++){
        temp = first_part->val + rev_second_part->val;
        if(temp > max) max = temp;
        first_part= first_part->next;
        rev_second_part = rev_second_part->next;
    }
    return max;
}