/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null) return head;
        while(head.next.val == head.val){
            while(head.next != null){
                if(head.next.val == head.val) {
                    head = head.next;
                }else break;
            }
            head = head.next;
            if(head == null || head.next == null) break;
        }
        ListNode index = head;
        if(index == null || index.next == null) return head;
        ListNode check = index.next;
        while(check != null && check.next != null){
            if(check.next.val == check.val){
                while(check.next != null){
                    if(check.next.val == check.val){
                        check = check.next;
                    }else break;
                }
                index.next = check.next;
            }else{
                index = index.next;
            }
            check = index.next;
        }
        return head;
    }
}