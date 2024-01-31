using LL = long long;
class Solution {
public:
    LL dp[201][201];
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        for(const auto& p : prices) dp[p[0]][p[1]] = p[2];
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j) {
                for(int k = 1; k < j; ++k) dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);
                for(int k = 1; k < i; ++k) dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);
            }
        return dp[m][n];
    }
};