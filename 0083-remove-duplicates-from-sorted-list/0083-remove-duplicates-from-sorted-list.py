# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head
        while cur:
            if cur.next and cur.val == cur.next.val:
                next = cur.next
                while next.next and next.val == next.next.val:
                    next = next.next
                cur.next = next.next
            cur = cur.next
        return head