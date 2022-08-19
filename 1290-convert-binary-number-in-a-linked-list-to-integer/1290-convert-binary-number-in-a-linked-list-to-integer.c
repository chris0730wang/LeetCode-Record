/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int listlen(struct ListNode* head){
    int len = 0;
    while(head!=NULL){
        len++;
        head = head->next;
    }
    return len;
}

int getDecimalValue(struct ListNode* head){
    if(head == NULL) return NULL;
    struct ListNode* index = head;
    int len = listlen(head), res = 0;
    if(len == 1){
        return head->val;
    }
    while(index != NULL){
        if(index->val != 0){
            int sum = 1;
            for(int i=0; i<len-1; i++){
                sum *= 2;
            }
            res += sum;
        }
        index = index->next;
        len--;
    }
    return res;
}