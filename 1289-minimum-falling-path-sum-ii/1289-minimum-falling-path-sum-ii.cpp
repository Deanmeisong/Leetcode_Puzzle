class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = 0; i < n; ++i) dp[0][i] = grid[0][i];
        
        for(int r = 1; r < m; ++r)
            for(int c = 0; c < n; ++c) {
                int min_value = INT_MAX;
                for(int k = 0; k < n; ++k) {
                    if(k == c) continue;
                    min_value = min(min_value, dp[r - 1][k]);
                }
                dp[r][c] = grid[r][c] + min_value;
            }
        
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};