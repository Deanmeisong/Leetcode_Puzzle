# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.sum = 0
    def bstToGst(self, root):
        if root:
            self.bstToGst(root.right)
            self.sum += root.val
            root.val = self.sum
            self.bstToGst(root.left)
        return root
        