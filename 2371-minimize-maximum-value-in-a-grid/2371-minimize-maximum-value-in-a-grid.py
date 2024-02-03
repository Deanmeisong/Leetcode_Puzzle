class Solution(object):
    def minScore(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        m, n = len(grid), len(grid[0])
        nums = [(v, i, j) for (i, row) in enumerate(grid) for (j, v) in enumerate(row)]
        
        nums.sort()
        rm, cm, ans = [0] * m, [0] * n, [[0] * n for _ in range(m)]
        
        for _, i, j in nums:
            ans[i][j] = max(rm[i], cm[j]) + 1
            rm[i] = cm[j] = ans[i][j]
            
        return ans