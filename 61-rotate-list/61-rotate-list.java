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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null || k == 0) return head;
        ListNode index = head;
        int len=0;
        while(index != null){
            index = index.next;
            len++;
        }
        if(k >= len) k %= len;
        index = head;
        for(int i=0; i<k; i++){
            while(index.next != null){
                if(index.next.next == null) break;
                index = index.next;
            }
            ListNode temp = index.next;
            temp.next = head;
            index.next = null;
            head = temp;
            index = head;
        }
        
        return head;
    }
}