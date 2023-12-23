class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        n = min(steps//2+2, arrLen)
        dp = [0] * n
        M = 10**9 + 7
        dp[0] = 1
        for k in range(steps):
            dp2 = dp[:]
            for i in range(n):
                dp[i] = dp2[i] + (dp2[i-1] if i>=1 else 0) + (dp2[i+1] if i+1<n else 0)
                dp[i] %= M
        return dp[0]