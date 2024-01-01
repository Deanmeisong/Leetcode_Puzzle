class Solution(object):
    def checkWays(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: int
        """
        relative = [[] for _ in range(501)]
        isRelative = [[0] * 501 for _ in range(501)]
        
        flag, root = 1, -1
        nodeSet, visited = set(), set()
        
        for p in pairs:
            nodeSet.add(p[0]), nodeSet.add(p[1])
            relative[p[0]].append(p[1]), relative[p[1]].append(p[0])
            isRelative[p[0]][p[1]], isRelative[p[1]][p[0]] = 1, 1
        
        node = list(nodeSet)
        node.sort(key = lambda x : len(relative[x]))
        
        for i in range(len(node)):
            j = i + 1
            while j < len(node) and isRelative[node[i]][node[j]] == 0: j += 1
            if j < len(node):
                for rel in relative[node[i]]:
                    if rel != node[j] and isRelative[rel][node[j]] == 0: return 0
                if len(relative[node[i]]) == len(relative[node[j]]): flag = 2
            else:
                if root == -1: root = node[i]
                else: return 0
                
        return flag
                