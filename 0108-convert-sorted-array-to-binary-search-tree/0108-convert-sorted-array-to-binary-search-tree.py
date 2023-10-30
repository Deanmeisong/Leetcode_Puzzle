# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        n = len(nums)
        def dfs(left, right):
            if left > right:
                return None
            m = left + (right - left) // 2
            root = TreeNode(nums[m])
            root.left = dfs(left, m - 1)
            root.right = dfs(m + 1, right)
            return root
        return dfs(0, n - 1)
        