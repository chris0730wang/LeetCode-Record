/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* node = head;
    struct ListNode* return_node = head;
    struct ListNode* remove_node;
    int len=0;
    while(node!=NULL){
        len++;
        node = node->next;
    }
    node = head;
    int remove_num = len - n + 1;
    if(remove_num==1){
        remove_node = node;
        return_node = remove_node->next;
        remove_node->next = NULL;
    } else{
        for(int i=1; i<remove_num-1; i++){
            node = node->next;
        }
        remove_node = node->next;
        node->next = remove_node->next;
        remove_node->next = NULL;
    }   
    return return_node;
}