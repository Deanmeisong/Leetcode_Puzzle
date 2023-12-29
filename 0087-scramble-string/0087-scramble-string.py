class Solution(object):
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """  
        n = len(s1)
        dp = [[[False] * (n + 1) for _ in range(n)] for _ in range(n + 1)]
        for k in range(1, n + 1):
            for i in range(n - k + 1):
                for j in range(n - k + 1):
                    if k == 1:
                        dp[i][j][k] = s1[i] == s2[j]
                        continue
                    for u in range(1, k):
                        o1 = dp[i][j][u] and dp[i + u][j + u][k - u]
                        o2 = dp[i][j + k - u][u] and dp[i + u][j][k - u]
                        if o1 or o2:
                            dp[i][j][k] = True
                            break
        return dp[0][0][n]
        