class Solution(object):
    def numberOfWays(self, numPeople):
        """
        :type numPeople: int
        :rtype: int
        """
        m = 1000000007
        dp = [0] * (numPeople//2 + 1)
        dp[0] = 1
        for i in range(1, numPeople//2 + 1):
            for j in range(i):
                dp[i] += dp[j] * dp[i-j-1]
                dp[i] %= m
        return dp[numPeople // 2]