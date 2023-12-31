class Solution {
public:
    # define ll long long
    int waysToDistribute(int n, int k) {
        vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, 0));
        ll m = 1e9 + 7;
        for(int i = 0; i <= k; ++i) dp[i][i] = 1;
        for(int i = 1; i <= k; ++i)
            for(int j = i + 1; j <= n; ++j) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1] * i) % m;
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % m;
            }
        return dp[k][n];
    }
};