class Solution {
public:
    int numWays(int steps, int arrLen) {
        int n = min(arrLen, steps / 2 + 2);
        long M = 1e9 + 7;
        vector<long> dp(n);
        dp[0] = 1;
        for(int k = 0; k < steps; ++k) {
             auto dp2 = dp;
            for(int i = 0; i < n; ++i) {
                dp[i] = dp2[i] + (i >= 1 ? dp2[i - 1] : 0) + (i < n - 1 ? dp2[i + 1] : 0);
                dp[i] %= M;
            }
        }
  
        return dp[0];
    }
};