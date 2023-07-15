class Solution {
    public int checkRecord(int n) {
        int ans = 0;
        int[][][] dp = new int[n + 1][2][3];
        int mod = 1_000_000_007;
        dp[0][0][0] = 1;
        for(int i = 1; i <= n; ++i) {
            // if present
            for(int j = 0; j < 2; ++j)
                for(int k = 0; k < 3; ++k) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % mod;
                }
            // if absent
            for(int k = 0; k < 3; ++k) dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % mod;
            // if late
            for(int j = 0; j < 2; ++j)
                for(int k = 1; k < 3; ++k) {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % mod;
                }
        }
        
        for(int j = 0; j < 2; ++j)
            for(int k = 0; k < 3; ++k)
                ans = (ans + dp[n][j][k]) % mod;
        
        return ans;
    }
}