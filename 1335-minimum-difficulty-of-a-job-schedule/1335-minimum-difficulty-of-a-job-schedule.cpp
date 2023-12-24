class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int D) {
        int n = jobDifficulty.size();
        if(n < D) return -1;
        vector<vector<int>> dp(n + 1, vector<int>(D + 1, INT_MAX/2));
        dp[0][0] = 0;
        for(int i = 1; i <= n; ++i)
            for(int d = 1; d <= D; ++d) {
                int max_val = 0;
                for(int j = i - 1; j >= d - 1; --j) {
                    max_val = max(max_val, jobDifficulty[j]);
                    dp[i][d] = min(dp[i][d], dp[j][d - 1] + max_val);
                }
            }
        return dp[n][D];
    }
};