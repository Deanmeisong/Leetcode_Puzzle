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
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode dummy = new ListNode(0); dummy.next = head; head = dummy;
        while(head != null && head.next != null && head.next.next != null) {
            ListNode n1 = head.next; ListNode n2 = n1.next;
            n1.next = n2.next;
            n2.next = n1;
            head.next = n2;
            head = n1;
        }
        return dummy.next;
    }
}