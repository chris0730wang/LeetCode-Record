/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeNodes(struct ListNode* head){
    struct ListNode *first, *current, *previous = NULL;
    int sum = 0;
    
    head = head->next;
    while (head != NULL) {
        if (head->val == 0) {
            current = malloc(sizeof(struct ListNode));
            current->val = sum;
            sum = 0;
            
            if (previous == NULL) first = current;
            else previous->next = current;
            current->next = NULL;
            previous = current;
        }
        else {
            sum += head->val;       
        }
        head = head->next;
    }
    return first;
}



