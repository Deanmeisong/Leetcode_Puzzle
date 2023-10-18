using LL = long long;
class Solution {
public:
    LL mod = 1e9 + 7;
    int countSpecialSubsequences(vector<int>& nums) {
        vector<LL> dp(3);
        dp[0] = 1;
        for(int x : nums) {
            if(x == 0) {
                dp[0] = (2 * dp[0]) % mod;
            } else if(x == 1) {
                dp[1] = (dp[0] - 1 + 2 * dp[1]) % mod;
            } else if(x == 2) {
                dp[2] = (dp[1] + 2 * dp[2]) % mod;
            }
        }
        return dp[2];
    }
};