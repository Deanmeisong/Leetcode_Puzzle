class Solution {
public:
   
    int climbStairs(int n) {
        // int dp[n + 1];
        if(n == 1) return 1;
        if(n == 2) return 2;
        int dp1 = 1, dp2 = 2, dpn = 3;
        for(int i = 3; i <= n; ++i) {
            dpn = dp1 + dp2;
            dp1 = dp2;
            dp2 = dpn;
        }
        return dpn;
    }
};