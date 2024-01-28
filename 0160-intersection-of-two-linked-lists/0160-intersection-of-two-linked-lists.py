# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, A: ListNode, B: ListNode) -> Optional[ListNode]:
        a, b = A, B
        while a != b:
            if a: a = a.next
            else: a = B
            if b: b = b.next
            else: b = A
        return a