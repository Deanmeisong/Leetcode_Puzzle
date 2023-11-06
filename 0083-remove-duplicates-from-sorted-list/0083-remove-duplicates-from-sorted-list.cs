/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode DeleteDuplicates(ListNode head) {
        ListNode cur = head;
        while (cur != null) {
            if (cur.next != null && cur.val == cur.next.val) {
                ListNode next = cur.next;
                while (next.next != null && next.val == next.next.val) {
                    next = next.next;
                }
                cur.next = next.next;
            }
            cur = cur.next;
        }
        return head;
    }
}