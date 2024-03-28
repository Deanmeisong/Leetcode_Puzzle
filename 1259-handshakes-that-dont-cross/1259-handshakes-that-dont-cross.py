class Solution:
    def numberOfWays(self, numPeople: int) -> int:
        m = 1000000007
        dp = [0] * (numPeople//2 + 1)
        dp[0] = 1
        for i in range(1, numPeople//2 + 1):
            for j in range(0, i):
                dp[i] += dp[j] * dp[i-j-1] % m
                dp[i] %= m
        return dp[numPeople//2]