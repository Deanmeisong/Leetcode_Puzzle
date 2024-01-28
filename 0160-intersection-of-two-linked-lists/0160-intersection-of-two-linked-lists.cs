/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode GetIntersectionNode(ListNode A, ListNode B) {
        ListNode a = A; ListNode b = B;
        while(a != b) {
            a = a != null ? a.next : B;
            b = b != null ? b.next : A;
        }
        return a;
    }
}