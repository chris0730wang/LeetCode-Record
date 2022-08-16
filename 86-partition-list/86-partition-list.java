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
    public ListNode partition(ListNode head, int x) {
        if(head == null || head.next == null) return head;
        ListNode partless = new ListNode(0, null);
        ListNode partmore = new ListNode(0, null);
        ListNode pl_index = partless, pm_index = partmore;
        ListNode index = head;
        while(index != null){
            if(index.val < x){
                pl_index.next = index;
                pl_index = pl_index.next;
                pm_index.next = null;
            }else{
                pm_index.next = index;
                pm_index = pm_index.next;
                pl_index.next = null;
            }
            index = index.next;
        }
        pl_index.next = partmore.next;
        return partless.next;
    }
}