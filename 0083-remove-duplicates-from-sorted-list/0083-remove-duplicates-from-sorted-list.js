/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
    let cur = head;
    while (cur !== null) {
        if (cur.next !== null && cur.val === cur.next.val) {
            let nxt = cur.next;
            while (nxt.next !== null && nxt.val === nxt.next.val) {
                nxt = nxt.next;
            }
            cur.next = nxt.next;
        }
        cur = cur.next;
    }
    return head;
};