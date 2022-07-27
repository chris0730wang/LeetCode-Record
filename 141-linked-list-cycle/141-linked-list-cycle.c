/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode* index_node=head, *check_node=NULL;
    
    if(!head || !(head->next))
        return false;
    
    check_node=head->next;
    
    while(index_node!=check_node)
    {
        if(check_node==NULL)
        {
            return false;
        }
        index_node=index_node->next;
        if(check_node->next && check_node->next->next)
            check_node=check_node->next->next;
        else
            check_node = check_node->next;
    }
    return true;
}