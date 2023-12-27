"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""

class Solution(object):
    def moveSubTree(self, root, p, q):
        """
        :type root: Node
        :type p: Node
        :type q: Node
        :rtype: Node
        """
        
        if p in q.children: return root
        d = Node()
        d.children.append(root)
        
        pp = self.dfs_parent(d, p)
        q_in_p = self.dfs_parent(p, q)
        
        pi = pp.children.index(p)
        pp.children.pop(pi)
        
        q.children.append(p)
    
        if q_in_p:
            q_in_p.children.remove(q)
            pp.children.insert(pi, q)
        
        return d.children[0]
    
    def dfs_parent(self, n, tar):
        if tar in n.children: return n
        for x in n.children:
            ans = self.dfs_parent(x, tar)
            if ans: return ans
        return None
        