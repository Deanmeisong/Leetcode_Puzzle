# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def countGreatEnoughNodes(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        self.ans = 0
        def push(pq, x):
            heappush(pq, x)
            if len(pq) > k:
                heappop(pq)
                
        def dfs(root):
            if not root: return []
            l, r = dfs(root.left), dfs(root.right)
            for x in r:
                push(l, x)
            if len(l) == k and -l[0] < root.val:
                 self.ans += 1
            push(l, -root.val)
            return l
        
        dfs(root)
        return self.ans
                