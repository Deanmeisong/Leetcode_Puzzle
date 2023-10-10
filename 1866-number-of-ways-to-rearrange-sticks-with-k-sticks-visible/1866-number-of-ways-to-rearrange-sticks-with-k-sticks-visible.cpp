class Solution {
public:
    long dp[1005][1005];
    long rearrangeSticks(int n, int k) {
        int kMod = 1e9 + 7;
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= min(n, k); ++j) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * (i - 1) % kMod) % kMod;
            }
        return dp[n][k];
    }
};