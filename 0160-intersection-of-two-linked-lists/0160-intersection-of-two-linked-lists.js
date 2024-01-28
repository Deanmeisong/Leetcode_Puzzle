/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(A, B) {
    let a = A; let b = B;
    while(a !== b) {
        a = a != null ? a.next : B;
        b = b != null ? b.next : A;
    }
    return a;
};