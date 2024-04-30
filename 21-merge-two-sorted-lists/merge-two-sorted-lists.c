/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* tmp = ret;
	while(list1 && list2){
		struct ListNode* tmpNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		if(list1->val < list2->val){
			tmpNode->val = list1->val;
			list1 = list1->next;
		}
		else{
			tmpNode->val = list2->val;
			list2 = list2->next;
		}
		tmp->next = tmpNode;
		tmp = tmpNode;
	}
	if(!list1) tmp->next = list2;
	if(!list2) tmp->next = list1;
	return ret->next;
}