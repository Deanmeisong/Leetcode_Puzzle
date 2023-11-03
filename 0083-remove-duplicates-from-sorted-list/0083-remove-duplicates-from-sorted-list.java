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
        ListNode cur = head;
        while(cur != null) {
            if(cur.next != null && cur.val == cur.next.val) {
                ListNode nxt = cur.next;
                while(nxt.next != null && nxt.val == nxt.next.val) {
                    nxt = nxt.next;
                }
                cur.next = nxt.next;
            }
            cur = cur.next;
        }
        return head;
    }
}