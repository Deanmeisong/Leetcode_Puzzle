class Solution(object):
    def minScore(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        m, n = len(grid), len(grid[0])
        nums = [(v, i, j) for (i, row) in enumerate(grid) for (j, v) in enumerate(row)]
        nums.sort()
        
        rm = [0] * m
        cm = [0] * n
        ans = [[0] * n for _ in range(m)]
        
        for num in nums:
            i, j = num[1], num[2]
            ans[i][j] = max(rm[i], cm[j]) + 1
            rm[i] = cm[j] = ans[i][j]
            
        return ans