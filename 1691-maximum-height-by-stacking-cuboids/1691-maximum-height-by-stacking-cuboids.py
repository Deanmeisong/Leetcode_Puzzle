class Solution(object):
    def maxHeight(self, cuboids):
        """
        :type cuboids: List[List[int]]
        :rtype: int
        """
        n = len(cuboids)
        for c in cuboids: c.sort()
        cuboids.sort()
        dp = [0] * n
        for i in range(n):
            dp[i] = cuboids[i][2]
            for j in range(0, i):
                if cuboids[j][0] <= cuboids[i][0] and cuboids[j][1] <= cuboids[i][1] and cuboids[j][2] <= cuboids[i][2]:
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2])
        
        return max(dp)