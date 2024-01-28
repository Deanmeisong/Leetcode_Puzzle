/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode A, ListNode B) {
        ListNode a = A; ListNode b = B;
        while(a != b) {
            a = a != null ? a.next : B;
            b = b != null ? b.next: A;
        }
        return a;
    }
}