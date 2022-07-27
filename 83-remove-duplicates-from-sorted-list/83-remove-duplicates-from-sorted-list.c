/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* index_node = head;
    struct ListNode* check_node;
    if(index_node == NULL) return NULL;
    if(index_node->next == NULL) return index_node;
    while(index_node != NULL && index_node->next != NULL){
        check_node = index_node->next;
        while(check_node != NULL && check_node->val == index_node->val){
            check_node = check_node->next;
        }
        index_node->next = check_node;
        index_node = index_node->next;
    }
    return head;
}