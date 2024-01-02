# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head: return head
        prev, cur, ans = None, head, head.next
        while cur and cur.next:
            nxt = cur.next
            if prev: prev.next = nxt
            cur.next, nxt.next = nxt.next, cur
            prev, cur = cur, cur.next
        return ans or head