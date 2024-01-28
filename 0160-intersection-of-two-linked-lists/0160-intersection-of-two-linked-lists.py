# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, A, B):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        a, b = A, B
        while a != b:
            if a: a = a.next
            else: a = B
            if b: b = b.next
            else: b = A
        return a