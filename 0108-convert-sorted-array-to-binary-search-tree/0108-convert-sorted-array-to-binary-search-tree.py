# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
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
            